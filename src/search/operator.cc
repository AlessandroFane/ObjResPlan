#include "globals.h"
#include "operator.h"

#include <string>
#include <iostream>
using namespace std;

Prevail::Prevail(istream &in) {
    in >> var >> prev;
}

PrePost::PrePost(istream &in) {
    int condCount;
    in >> condCount;
    for (int i = 0; i < condCount; i++)
        cond.push_back(Prevail(in));
    in >> var >> pre >> post;
}

Operator::Operator() {
    marked = false;
    nondet_index = -1;
    is_an_axiom = false;
    name = "dummy_action";
    cost = -1;
}

Operator::Operator(istream &in, bool axiom) {
    marked = false;
    nondet_index = -1;

    is_an_axiom = axiom;
    if (!is_an_axiom) {
        check_magic(in, "begin_operator");
        in >> ws;
        getline(in, name);
        int count;
        in >> count;
        for (int i = 0; i < count; i++)
            prevail.push_back(Prevail(in));
        in >> count;
        for (int i = 0; i < count; i++)
            pre_post.push_back(PrePost(in));

        int op_cost;
        in >> op_cost;
        cost = g_use_metric ? op_cost : 1;

        g_min_action_cost = min(g_min_action_cost, cost);
        g_max_action_cost = max(g_max_action_cost, cost);

        check_magic(in, "end_operator");
        
        // The nondet name is the original name of the non-deterministic action
        if (name.find("_DETDUP") == string::npos) {
            nondet_name = name;
        } else {
            nondet_name = name.substr(0, name.find("_DETDUP")) + name.substr(name.find(" "), string::npos);
        }
        
    } else {
        name = "<axiom>";
        cost = 0;
        check_magic(in, "begin_rule");
        pre_post.push_back(PrePost(in));
        check_magic(in, "end_rule");
    }
    
    marker1 = marker2 = false;
    
    
    
    /* ********************
     * 
     *  !!WARNING!!
     * 
     *   This operation doesn't check for inconsistencies
     *    because we assume that was done to construct the
     *    g_regressable_cond_ops data structure (see the
     *    generate_regressable_ops function).
     * 
     * ************* */
     
    // Deal with the all-fire context (essentially every conditional head
    //  and precondition rolled into one state)
    all_fire_context = new PartialState();
    
    for (int i = 0; i < pre_post.size(); i++) {
        (*all_fire_context)[pre_post[i].var] = pre_post[i].pre;
        
        for (int j = 0; j < pre_post[i].cond.size(); j++) {
            (*all_fire_context)[pre_post[i].cond[j].var] = pre_post[i].cond[j].prev;
        }
    }
    
    for (int i = 0; i < prevail.size(); i++)
        (*all_fire_context)[prevail[i].var] = prevail[i].prev;
    

    
    // Prima di aggiungere le stringhe alla lista, assicurati che la lista sia già dichiarata e inizializzata correttamente

    for (int i = 0; i < prevail.size(); ++i) {
        // Ottieni il vettore di stringhe oggetti
        const std::vector<std::string>& oggetti = g_fact_names[prevail[i].var][prevail[i].prev].oggetti;
        
        // Itera attraverso il vettore oggetti
        for (int j = 0; j < oggetti.size(); ++j) {
            const std::string& oggetto = oggetti[j];
            
            // Controlla se l'oggetto è già presente nella lista
            bool presente = false;
            for (int k = 0; k < objectList.size(); ++k) {
                if (objectList[k] == oggetto) {
                    presente = true;
                    break;
                }
            }
            
            // Aggiungi l'oggetto alla lista solo se non è già presente
            if (!presente) {
                objectList.push_back(oggetto);
            }
        }
    }
    for (int i = 0; i < pre_post.size(); ++i) {
        // Ottieni il vettore di stringhe oggetti
        
        if (-1 != pre_post[i].pre){
            const std::vector<std::string>& oggetti = g_fact_names[pre_post[i].var][pre_post[i].pre].oggetti;
            
        
            // cout << oggetti.size() << endl;

            
            // if(oggetti.size()<10000){
            // Itera attraverso il vettore oggetti
            for (int j = 0; j < oggetti.size(); ++j) {
                const std::string& oggetto = oggetti[j];
                
                // Controlla se l'oggetto è già presente nella lista
                bool presente = false;
                for (int k = 0; k < objectList.size(); ++k) {
                    if (objectList[k] == oggetto) {
                        presente = true;
                        break;
                    }
                }
                // Aggiungi l'oggetto alla lista solo se non è già presente
                if (!presente) {
                    objectList.push_back(oggetto);
                }
            }
            // }



        }
        
        const std::vector<std::string>& oggetti2 = g_fact_names[pre_post[i].var][pre_post[i].post].oggetti;
        
        // Itera attraverso il vettore oggetti2
        for (int j = 0; j < oggetti2.size(); ++j) {

            const std::string& oggetto = oggetti2[j];
            
            // Controlla se l'oggetto è già presente nella lista
            bool presente = false;
            for (int k = 0; k < objectList.size(); ++k) {
                if (objectList[k] == oggetto) {
                    presente = true;
                    break;
                }
            }
            
            // Aggiungi l'oggetto alla lista solo se non è già presente
            if (!presente) {
                objectList.push_back(oggetto);
            }
        }
    }
    fragile =false;
    if (hasIntersection(objectList, oggetti_fragili)){
        fragile = true;
    }

}




void Prevail::dump() const {
    const string &fact_name = g_fact_names[var][prev].stringa;
    if (fact_name != "<none of those>")
        cout << fact_name;
    else
        cout << "[" << g_variable_name[var] << "] None of those.";
}

void PrePost::dump() const {
    
    if (-1 == pre)
        cout << "anything -> ";
    else {
        const string &pre_name = g_fact_names[var][pre].stringa;
        if (pre_name != "<none of those>")
            cout << pre_name << " -> ";
        else
            cout << "[" << g_variable_name[var] << "] None of those." << " -> ";
    }
    
    const string &post_name = g_fact_names[var][post].stringa;
    if (post_name != "<none of those>")
        cout << post_name;
    else
        cout << "[" << g_variable_name[var] << "] None of those.";
    if (!cond.empty()) {
        cout << " if";
        for (int i = 0; i < cond.size(); i++) {
            cout << " ";
            cond[i].dump();
        }
    }
}

void Operator::dump() const {
    cout << name << " (" << nondet_name << "):";
    for (int i = 0; i < prevail.size(); i++) {
        cout << " [";
        prevail[i].dump();
        cout << "]";
    }
    for (int i = 0; i < pre_post.size(); i++) {
        cout << " [";
        pre_post[i].dump();
        cout << "]";
    }
    cout << endl;
}


std::vector<std::string> Operator::obj() const {
    return objectList;
}

bool Operator::isFragile() const {
    return fragile;
}

