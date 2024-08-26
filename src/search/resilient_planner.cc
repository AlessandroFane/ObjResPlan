/** @file */

#include "globals.h"
#include "operator.h"
#include "option_parser.h"
#include "ext/tree_util.hh"
#include "timer.h"
#include "utilities.h"
#include "search_engines/search_engine.h"
#include "regression.h"
#include "policy.h"
#include "partial_state.h"
#include "resilient_node.h"
#include "resilient_policy.h"
#include "print_utils.h"

#include <math.h>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <tr1/functional>
#include <tr1/unordered_map>


using namespace std;

bool resiliency_check(ResilientNode node);
bool replan(ResilientNode current_node, SearchEngine *engine);
std::list<Operator> extract_solution(State state);
void update_non_resilient_nodes(ResilientNode node);
void add_non_resilient_deadends(ResilientNode node);
std::vector<Operator> FragileActions(const std::vector<Operator>& actions, const std::vector<std::string>& objects);
std::vector<std::string> intersection(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2);
void generatePowerSetInRange(vector<Operator>& vec, int minSize, vector<set<Operator> >& subsets);
std::set<Operator> getElements(const std::set<std::set<Operator> >& outer_set);


std::tr1::unordered_map<int, ResilientNode> resilient_nodes;
std::tr1::unordered_map<int, ResilientNode> non_resilient_nodes;
std::stack<ResilientNode> open;

int main(int argc, const char **argv)
{     
    // cout << "~~~~~~~~~~~~~~~~~" << oggetti_fragili_input.size()<< endl;
    // for (size_t i = 0; i < oggetti_fragili_input.size(); ++i){
    //     cout<< "..." << oggetti_fragili_input[i]<<"...."<<endl;
    //     oggetti_fragili.push_back(oggetti_fragili_input[i]);
    // }

    
    
    // oggetti_fragili.push_back("bicicletta1a");
    // oggetti_fragili.push_back("bicicletta2a");
    // oggetti_fragili.push_back("bicicletta3a");
    // oggetti_fragili.push_back("bicicletta4a");
    // oggetti_fragili.push_back("bicicletta5a");
    // oggetti_fragili.push_back("bicicletta6a");
    // oggetti_fragili.push_back("bicicletta7a");
    // oggetti_fragili.push_back("bicicletta8a");
    // oggetti_fragili.push_back("bicicletta9a");
    // oggetti_fragili.push_back("bicicletta10a");
    // oggetti_fragili.push_back("bicicletta12a");
    // oggetti_fragili.push_back("bicicletta13a");
    // oggetti_fragili.push_back("bicicletta16a");
    // oggetti_fragili.push_back("bicicletta17a");

    // oggetti_fragili.push_back("bicicletta4b");
    // oggetti_fragili.push_back("bicicletta5b");
    // oggetti_fragili.push_back("bicicletta6b");
    // oggetti_fragili.push_back("bicicletta7b");
    // oggetti_fragili.push_back("bicicletta8b");
    // oggetti_fragili.push_back("bicicletta9b");
    // oggetti_fragili.push_back("bicicletta10b");
    // oggetti_fragili.push_back("bicicletta12b");
    // oggetti_fragili.push_back("bicicletta13b");
    // oggetti_fragili.push_back("bicicletta16b");

    // oggetti_fragili.push_back("bicicletta4c");
    // oggetti_fragili.push_back("bicicletta5c");
    // oggetti_fragili.push_back("bicicletta6c");
    // oggetti_fragili.push_back("bicicletta7c");
    // oggetti_fragili.push_back("bicicletta8c");
    // oggetti_fragili.push_back("bicicletta9c");
    // oggetti_fragili.push_back("bicicletta10c");
    // oggetti_fragili.push_back("bicicletta12c");
    // oggetti_fragili.push_back("bicicletta13c");
    // oggetti_fragili.push_back("bicicletta16c");

    // oggetti_fragili.push_back("bicicletta4d");
    // oggetti_fragili.push_back("bicicletta6d");
    // oggetti_fragili.push_back("bicicletta7d");
    // oggetti_fragili.push_back("bicicletta8d");
    // oggetti_fragili.push_back("bicicletta9d");
    // oggetti_fragili.push_back("bicicletta12d");
    // oggetti_fragili.push_back("bicicletta13d");
    // oggetti_fragili.push_back("bicicletta16d");

    // oggetti_fragili.push_back("bicicletta4e");
    // oggetti_fragili.push_back("bicicletta9e");
    // oggetti_fragili.push_back("bicicletta12e");
    // oggetti_fragili.push_back("bicicletta16e");

    // oggetti_fragili.push_back("bicicletta9f");
    // oggetti_fragili.push_back("bicicletta16f");

    // oggetti_fragili.push_back("bicicletta9g");
    // oggetti_fragili.push_back("bicicletta16g");

    // oggetti_fragili.push_back("bicicletta9h");

    // oggetti_fragili.push_back("bicicletta9i");
    

    // oggetti_fragili.push_back("auto1_17");
    // oggetti_fragili.push_back("auto1_2");
    // oggetti_fragili.push_back("auto2_17");
    // oggetti_fragili.push_back("auto2_1");
    // oggetti_fragili.push_back("auto17_1");
    // oggetti_fragili.push_back("auto17_2");

    // oggetti_fragili.push_back("metro1a");
    // oggetti_fragili.push_back("metro2a");
    // oggetti_fragili.push_back("metro3a");
    // oggetti_fragili.push_back("metro4a");
    // oggetti_fragili.push_back("metro5a");
    // oggetti_fragili.push_back("metro6a");
    // oggetti_fragili.push_back("metro7a");
    // oggetti_fragili.push_back("metro8a");
    // oggetti_fragili.push_back("metro9a");
    // oggetti_fragili.push_back("metro10a");
    // oggetti_fragili.push_back("metro11a");
    // oggetti_fragili.push_back("metro12a");
    // oggetti_fragili.push_back("metro13a");
    // oggetti_fragili.push_back("metro14a");
    // oggetti_fragili.push_back("metro15a");
    // oggetti_fragili.push_back("metro16a");
    
    // oggetti_fragili.push_back("metro2b");
    // oggetti_fragili.push_back("metro3b");
    // oggetti_fragili.push_back("metro4b");
    // oggetti_fragili.push_back("metro5b");
    // oggetti_fragili.push_back("metro6b");
    // oggetti_fragili.push_back("metro7b");
    // oggetti_fragili.push_back("metro8b");
    // oggetti_fragili.push_back("metro9b");
    // oggetti_fragili.push_back("metro10b");
    // oggetti_fragili.push_back("metro11b");
    // oggetti_fragili.push_back("metro12b");
    // oggetti_fragili.push_back("metro13b");
    // oggetti_fragili.push_back("metro14b");
    // oggetti_fragili.push_back("metro15b");
    // oggetti_fragili.push_back("metro16b");
    // oggetti_fragili.push_back("metro17b");

    // oggetti_fragili.push_back("bus1");
    // oggetti_fragili.push_back("bus2");
    // oggetti_fragili.push_back("bus3");
    // oggetti_fragili.push_back("train1");
    // oggetti_fragili.push_back("train2");
    // oggetti_fragili.push_back("train3");
    // oggetti_fragili.push_back("plane1");
    // oggetti_fragili.push_back("plane2");
    // oggetti_fragili.push_back("plane3");
    oggetti_fragili.push_back("bus1");
    oggetti_fragili.push_back("treno1");
    oggetti_fragili.push_back("aereo1");


    register_event_handlers();

    if (argc < 2)
    {
        cout << OptionParser::usage(argv[0]) << endl;
        exit_with(EXIT_INPUT_ERROR);
    }




    if (string(argv[1]).compare("--help") != 0)
        read_everything(cin);


    SearchEngine *engine = 0;
    g_policy = new Policy();
    list<PolicyItem *> regression_steps;

    g_timer_engine_init.stop();
    g_timer_engine_init.reset();
    g_timer_search.stop();
    g_timer_search.reset();
    g_timer_policy_build.stop();
    g_timer_policy_build.reset();
    g_timer_cycle.stop();
    g_timer_cycle.reset();
    g_timer_extraction.stop();
    g_timer_extraction.reset();
    g_timer_extract_policy.stop();
    g_timer_extract_policy.reset();

    g_mem_initial = mem_usage();

    // The input will be parsed twice:
    // once in dry-run mode, to check for simple input errors,
    // then in normal mode
    g_timer_engine_init.resume();
    try
    {
        OptionParser::parse_cmd_line(argc, argv, true);
        engine = OptionParser::parse_cmd_line(argc, argv, false);
    }
    catch (ParseError &pe)
    {
        cerr << pe << endl;
        exit_with(EXIT_INPUT_ERROR);
    }



    g_timer_engine_init.stop();

    generate_regressable_ops();

    /* HAZ: We create the policies even if we aren't using deadends, as
     *      they may be consulted by certain parts of the code. */
    g_deadend_policy = new Policy();
    g_deadend_states = new Policy();
    g_temporary_deadends = new Policy();

    if (((g_record_online_deadends || g_generalize_deadends) && !g_detect_deadends) ||
        ((g_partial_planlocal || g_plan_locally_limited) && !g_plan_locally) ||
        (g_optimized_scd && g_jic_limit == 0) ||
        (g_forgetpolicy && g_jic_limit > 0))
    {
        cout << "\n  Parameter Error: Make sure that the set of parameters is consistent.\n\n";
        exit(0);
    }
    cout << "Total allotted time (s): " << g_jic_limit << endl;

    g_operators_backup = g_operators;

    /***********************
     * Resilient Alghoritm *
     ***********************/




    // Stampa lista oggetti_fragili
    std::cout << "\nLista oggetti fragili: \n";
    for (std::vector<std::string>::const_iterator it = oggetti_fragili.begin(); it != oggetti_fragili.end(); ++it) {
        std::cout << *it << std::endl;
    }


    // Stampa di g_fact_names
    // for (int var = 0; var < g_fact_names.size(); ++var) {
    //         for (int fact = 0; fact < g_fact_names[var].size(); ++fact) {
    //             cout << "Variable " << var << ", Fact " << fact << " Stringa: " << g_fact_names[var][fact].stringa << " Oggetti: " << g_fact_names[var][fact].oggetti << " Fragile: " << g_fact_names[var][fact].fragile << endl;
    //         }
    //     }
    // Stampa di operator
    // for (int var = 0; var < g_operators.size(); ++var) {
            
    //             cout << "Operator " << g_operators[var].isFragile()  << endl;
            
    //     }



    // Create initial node and pushing to open stack
    std::set<std::set<Operator> > deactivated_ops_nodo_iniziale;
    State state = g_initial_state();
    ResilientNode initial_node = ResilientNode(g_initial_state(), g_max_faults, deactivated_ops_nodo_iniziale);
    // dump_everything();
    open.push(initial_node);

    g_timer_cycle.resume();

    // Start main loop
    while (!open.empty())
    {
        //  cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" << endl;
        // // cout << g_iteration << endl;
        // for (std::tr1::unordered_map<int, ResilientNode>::const_iterator it = non_resilient_nodes.begin(); it != non_resilient_nodes.end(); ++it) {
        //     it->second.dump();
        // }
        // // Stampa di operator
        // for (int var = 0; var < g_operators.size(); ++var) {
            
        //         cout << "Operator " << g_operators[var].isFragile()  << endl;
            
        // }
        // // Stampa il contenuto di g_dead_states
        //  cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
        g_iteration++;
                
        if (open.size() > g_max_dimension_open)
            g_max_dimension_open = open.size();

        ResilientNode current_node = open.top();
        open.pop();

        // Store current k and V in globals to use them later during replanning
        g_current_faults = current_node.get_k();
        g_current_forbidden_ops = current_node.get_deactivated_op();

        if (g_verbose)
        {
            cout << "\n----------------------------------------" << endl;
            cout << "\nIteration:" << g_iteration << endl;
            cout << "\nCurrent node:" << endl;
            current_node.dump();
        }
        // dump_everything();
        // Check if node is already in R sets
        if (resilient_nodes.find(current_node.get_id()) == resilient_nodes.end() && non_resilient_nodes.find(current_node.get_id()) == non_resilient_nodes.end())
        {
            if (resiliency_check(current_node))
            {
                g_successful_resiliency_check++;
                resilient_nodes.insert(make_pair(current_node.get_id(), current_node));

                if (g_verbose)
                    cout << "\nSuccessfull resiliency check." << endl;
            }
            else
            {
                if (g_verbose)
                    cout << "\nFailed resiliency check." << endl;
                

                // current_node.dump();
                

                // Replan function return true if successfull, the plan is stored in engine object
                if (!replan(current_node, engine))
                {
                    if (g_verbose)
                        cout << "\nFailed replan." << endl;
                    // If replanning fails, add current node to deadend and not resilient sets
                    // g_dead_states.insert(current_node.get_state().get_id());
                    // add_non_resilient_deadends(current_node); // S downarrow
                    update_non_resilient_nodes(current_node); // R downarrow
                }
                else
                {
                    g_successful_replan++;
                    if (g_verbose)
                        cout << "Successfull replanning" << endl;

                    // Save current initial state in a variable and computed plan for iteration
                    State current = g_initial_state();
                    std::vector<const Operator *> plan = engine->get_plan();

                    if (current_node.get_k() >= 1)
                    {
                        // Iterate over the plan to create the new nodes to push in the stack
                        for (vector<const Operator *>::iterator it = plan.begin(); it != plan.end(); ++it)
                        {
                            // Create node <tau_i-1, k, V>
                            ResilientNode res_node = ResilientNode(current, g_current_faults, g_current_forbidden_ops);
                            open.push(res_node);
                            
                            (*it)->dump();
                            if((*it)->isFragile())
                            {
                                // Create node <tau_i-1, k - 1, V U {pi_i}>
                                std::set<std::set<Operator> > actions = g_current_forbidden_ops;
                                std::set<Operator> post_actions;
                                std::vector<Operator> fragile_actions = FragileActions(g_operators, intersection((*it)->obj(),oggetti_fragili)); // *it = pi_i
                                // post_actions.insert(*it);
                                // Aggiungere le azioni fragili a post_actions
                                for (std::vector<Operator>::const_iterator it_action = fragile_actions.begin(); it_action != fragile_actions.end(); ++it_action) {
                                    post_actions.insert(*it_action);
                                }
                                // Aggiungi post_actions a forbidden_ops
                                actions.insert(post_actions);
                                ResilientNode res_node_f = ResilientNode(current, g_current_faults - 1, actions);
                                
                                // Push new nodes in the stack
                                open.push(res_node_f);

                                if (g_verbose)
                                {
                                    cout << "\nPushing in the stack with adjuntive failed:" << endl;
                                    res_node_f.dump();
                                }
                            }
                            else{
                                if (g_verbose)
                                    cout << "\nThe operator is not fragile and so we don't add actions" << endl;
                            }

                            current = g_state_registry->get_successor_state(current, *(*it));
                        }
                        // Add goal to resilient nodes
                        ResilientNode tau = ResilientNode(current, g_current_faults, g_current_forbidden_ops);
                        resilient_nodes.insert(make_pair(tau.get_id(), tau));
                    }
                    else // k = 0
                    {
                        
                        // Iterate over the plan to insert new nodes in resilient set
                        for (vector<const Operator *>::iterator it = plan.begin(); it != plan.end(); ++it)
                        {
                            ResilientNode res_node = ResilientNode(current, 0, current_node.get_deactivated_op());
                            relation_node_next_action[res_node.get_id()] = *(*it);
                            resilient_nodes.insert(make_pair(res_node.get_id(), res_node));

                            current = g_state_registry->get_successor_state(current, *(*it));
                        }
                        
                    }

                    // Perform regression over the computed plan
                    regression_steps.clear();
                    regression_steps = perform_regression(plan, g_matched_policy, 0, true);

                    // Update global policy with the new plan
                    g_policy->update_policy(regression_steps);

                    // Save policy relative to last computed plan mapping it with current <k,V>
                    Policy *resilient_policy = new Policy();
                    resilient_policy->update_policy(regression_steps);
                    
                    // Set per raccogliere tutti gli Operator
                    std::set<Operator> combined_forbidden_ops;

                    // Iterazione attraverso g_current_forbidden_ops
                    for (std::set<std::set<Operator> >::const_iterator it = g_current_forbidden_ops.begin(); it != g_current_forbidden_ops.end(); ++it) {
                        const std::set<Operator>& inner_set = *it;

                        // Unione di inner_set con combined_forbidden_ops
                        combined_forbidden_ops.insert(inner_set.begin(), inner_set.end());
                    }
                    g_resilient_policies.insert(std::make_pair(std::make_pair(g_current_faults, combined_forbidden_ops), resilient_policy));
                    if (g_verbose)
                    {
                        cout << "Plan:" << endl;
                        // resilient_policy->dump_simple();
                        for (vector<const Operator *>::iterator it = plan.begin(); it != plan.end(); ++it){
                            cout<<(*it)->get_name()<<endl;
                        }
                    }

                }
            }
        }

        if (g_max_iterations > 0 && g_iteration >= g_max_iterations)
            break;

        if (g_verbose)
        {
            cout << "Open list dimension: " << open.size() << endl;
            cout << "Resilient nodes dimension: " << resilient_nodes.size() << endl;
        }
    }

    g_timer_cycle.stop();

    // Verify if initial node is resilient
    if (resilient_nodes.find(initial_node.get_id()) != resilient_nodes.end())
    {
        cout << "\nInitial state is resilient, problem is " << g_max_faults << "-resilient!"
             << endl;

        if (g_dump_branches)
            print_branches();

        g_timer_extraction.resume();
        print_plan(g_plan_to_file, extract_solution(state));
        g_timer_extraction.stop();

        g_mem_post_alg = mem_usage();

        if (g_dump_resilient_policy)
        {
            ResilientPolicy res_policy = ResilientPolicy();
            g_timer_extract_policy.resume();
            res_policy.extract_policy(g_initial_state(), *(g_policy->get_items().front()->state), g_max_faults, resilient_nodes);
            g_timer_extract_policy.stop();
            print_resilient_policy_json(res_policy.get_policy());
            g_mem_extraction = mem_usage();
        }

        if (g_dump_resilient_nodes)
            print_resilient_nodes(resilient_nodes);
    }
    else
        cout << "\nInitial state is a deadend, problem is not " << g_max_faults << "-resilient!\n";

    print_statistics(resilient_nodes.size(), non_resilient_nodes.size());

    g_timer.stop();
    print_timings();
    print_memory();
}

/// Checks if the given node is resilient, using the current global policy to find the applicable next actions
/// then the StateRegistry linked to the state of the node to find the successors of the node.
/// The check is the same as the one in the pseudocode: (⟨s[a], k, V ⟩ ∈ R ∨ s[a] |= G) ∧ ⟨s, k − 1, V ∪ {a}⟩ ∈ R.
/// It also add the node to resilient_nodes list if the check succeds.
/// @param node The node to check if is resilient or not.
/// @return True if the node is resilient, false otherwise.
bool resiliency_check(ResilientNode node)
{
    
    if (resilient_nodes.empty())
        return false;

    PartialState state_to_check = PartialState(node.get_state());


    std::set<Operator> next_actions;
    list<PolicyItem *> current_policy = g_policy->get_items();
    // Find from the policy every action applicable in the current state, minus V
    for (std::list<PolicyItem *>::iterator it = current_policy.begin(); it != current_policy.end(); ++it)
    {
        // cout << "Current policyItem_____________________: ";
        // (*it)->dump();
        
        // Calcola il set delle operazioni disattivate
        std::set<Operator> deactivated_op;
        // cout << node.get_deactivated_op().size();
        // cout << "_____________________: ";
        // // Itera attraverso il set esterno
        // for (std::set<std::set<Operator> >::const_iterator outer_it = node.get_deactivated_op().begin();
        //     outer_it != node.get_deactivated_op().end(); ++outer_it) {

        //         std::size_t inner_set_size = outer_it->size();
        //         std::cout << "Dimensione del set interno corrente: " << inner_set_size << std::endl;
        //     // Itera attraverso ogni set interno
        //     for (std::set<Operator>::const_iterator inner_it = outer_it->begin();
        //         inner_it != outer_it->end(); ++inner_it) {
        //             std::cout << "Dimensione del set interno corrente: " << inner_set_size << std::endl;
        //             deactivated_op.insert(*inner_it);
        //             cout << "_____________________: "<< std::endl;
        //     }
        // }

        deactivated_op = getElements(node.get_deactivated_op());

        
        RegressionStep *reg_step = dynamic_cast<RegressionStep *>(*it);
        if (!reg_step->is_goal)
        {
            PartialState policy_state = PartialState(*reg_step->state);
            if ((*reg_step->state).is_implied(state_to_check) && !find_in_op_set(deactivated_op, reg_step->get_op()))
                next_actions.insert(reg_step->get_op());
        }
    }

    
    State state = node.get_state();
    StateRegistry *registry = const_cast<StateRegistry *>(&state.get_registry());


    // Resiliency check cycle
    for (std::set<Operator>::iterator it_o = next_actions.begin(); it_o != next_actions.end(); ++it_o)
    {
        // Print the current action
        // cout << "Current action_____________________: ";
        // it_o->dump();

        State successor = registry->get_successor_state(node.get_state(), *it_o);
        PartialState successor_p = PartialState(successor);
        ResilientNode successor_r = ResilientNode(successor, node.get_k(), node.get_deactivated_op()); // <s[a], k, V>
        if (resilient_nodes.find(successor_r.get_id()) != resilient_nodes.end())
        {
            
            if((it_o)->isFragile())
            {
                // Inizializza forbidden_plus_current con le operazioni disattivate dal nodo
                std::set<std::set<Operator> > forbidden_plus_current = node.get_deactivated_op();

                // Ottieni le azioni fragili
                std::vector<Operator> fragile_actions = FragileActions(g_operators, intersection((it_o)->obj(), oggetti_fragili));

                // Converte fragile_actions in un std::set<Operator>
                std::set<Operator> fragile_actions_set(fragile_actions.begin(), fragile_actions.end());

                // Aggiungi le azioni fragili a forbidden_plus_current
                forbidden_plus_current.insert(fragile_actions_set);
                
                ResilientNode current_r = ResilientNode(node.get_state(), node.get_k() - 1, forbidden_plus_current); // <s, k-1, V U {a}>
                if (resilient_nodes.find(current_r.get_id()) != resilient_nodes.end())
                {
                    relation_node_next_action[node.get_id()] = *it_o;
                    return true;
                }
            }
            else{
                relation_node_next_action[node.get_id()] = *it_o;
                return true;
            }

        }

            
    }
    return false;
}

/// @brief Try to replan from the state contained in current_node to the goal.
/// The search engine is resetted and not recreated to avoid the overhead of the initialization.
/// The plan is saved inside the engine object and can be retrieved from it.
/// @param current_node The node containing the state to replan from.
/// @param engine The search engine originally created.
/// @return True if the replan succeds, false otherwise.
bool replan(ResilientNode current_node, SearchEngine *engine)
{
    PartialState current_state = PartialState(current_node.get_state());

    // Reset initial state to the one contained in the node
    g_state_registry->reset_initial_state();
    for (int i = 0; i < g_variable_name.size(); i++)
        g_initial_state_data[i] = current_state[i];

    g_timer_engine_init.resume();
    engine->reset();
    g_timer_engine_init.stop();

    g_timer_search.resume();
    engine->search();
    g_timer_search.stop();

    if (g_dump_memory_replan_progression)
        cout << "Memory at replan #" << g_replan_counter + 1 << ": " << mem_usage() << "KB" << endl;
    // dump_everything();
    return engine->found_solution();
}

/// @brief Extract the final resilient plan, starting by the initial state
/// and choosing only actions that lead to resilient states until the goal
/// is reached.
/// @return The plan extracted.
std::list<Operator> extract_solution(State state)
{
    // Consider only the resilient nodes with k = max_faults to speed up later checks
    std::tr1::unordered_map<int, ResilientNode> resilient_nodes_k;
    for (std::tr1::unordered_map<int, ResilientNode>::iterator it = resilient_nodes.begin(); it != resilient_nodes.end(); ++it)
        if (it->second.get_k() == g_max_faults)
            resilient_nodes_k.insert(*it);

    std::list<Operator> plan;
    // State state = g_initial_state();
    PartialState partial_state = (PartialState)state;
                // ResilientNode partial_node = ResilientNode(state, g_max_faults, std::set<std::set<Operator> >());
                // partial_node.dump();
    list<PolicyItem *> current_policy = g_policy->get_items();
    std::set<Operator> next_actions;
    PolicyItem *goal_step = current_policy.front();
    PartialState goal = PartialState(*goal_step->state);

    PartialState policy_state;

    // Consider the state registry of the initial state, since it is the same for all states
    // found by registry.successor() in sequence
    StateRegistry *registry = const_cast<StateRegistry *>(&state.get_registry());

    while (!goal.is_implied(partial_state))
    {
        for (std::list<PolicyItem *>::iterator it = current_policy.begin(); it != current_policy.end(); ++it)
        {
            RegressionStep *reg_step = dynamic_cast<RegressionStep *>(*it);
            policy_state = PartialState(*reg_step->state);

            if (!reg_step->is_goal && policy_state.is_implied(partial_state))
            {
                State successor = registry->get_successor_state(state, *reg_step->op);
                PartialState successor_p = (PartialState)successor;
                ResilientNode successor_node = ResilientNode(successor, g_max_faults, std::set<std::set<Operator> >());
                successor_node.dump();
                if (resilient_nodes_k.find(successor_node.get_id()) != resilient_nodes_k.end() || goal.is_implied(successor_p))
                {
                    plan.push_back(*reg_step->op);
                    state = successor;
                    partial_state = successor_p;
                    break;
                }
            }
        }
    }
    return plan;
}

// /// @brief Update non resilient nodes with every <s,k',V'> such that V' is a subset of V and k' = k - |V \ V'|.
// /// @param node Deadend node to insert in the list non-resilient nodes.
// void update_non_resilient_nodes(ResilientNode node)
// {
//     cout << "\nInizio" << endl;
//     non_resilient_nodes.insert(make_pair(node.get_id(), node));
//     add_non_resilient_deadends(node);
//     std::set<std::set<Operator> > deactivated_op = node.get_deactivated_op();
//     std::cout << "La dimensione di deactivated_op è: " << deactivated_op.size() << std::endl;
//     // Iterazione attraverso deactivate_op utilizzando un ciclo for
//     for (std::set<std::set<Operator> >::const_iterator outer_it = deactivated_op.begin(); outer_it != deactivated_op.end(); ++outer_it) {
//         cout << "\nPrimo For" << endl;
//         std::set<std::set<Operator> > deactivated_op_copy = deactivated_op;
//         vector<std::set<Operator> > subsets;
//         std::set<Operator> v_set = *outer_it;
//         deactivated_op_copy.erase(v_set);
//         // Copia il set interno v_set in un vector<Operator> vec
//         std::vector<Operator> vec(v_set.begin(), v_set.end());

//         // bit masking method for finding subsets
//         // int set_size = vec.size();
//         // int pow_set_size = pow(2, set_size);
//         // std::cout << "La pow_set_size è: " << pow_set_size << std::endl;
//         // int counter, j;
//         // for (counter = 0; counter < pow_set_size; counter++)
//         // {
//         //     set<Operator> current;
//         //     for (j = 0; j < set_size; j++)
//         //         if (counter & (1 << j))
//         //             current.insert(vec[j]);
//         //     subsets.push_back(current);
//         // }


//         vector<set<Operator> > subsets;
//         // cout << (node.get_k()+node.get_deactivated_op().size()-g_max_faults) << endl;
//         // cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
//         generatePowerSetInRange(vec, (node.get_k()+node.get_deactivated_op().size()-g_max_faults), subsets);
//         // generatePowerSetInRange(vec, subsets);
//         // cout << subsets.size() << endl;
//         // cout << "dfsjhsfgsjfsgjohohgds" << endl;
//         for (int i = 0; i < subsets.size(); i++)
//         {
//             // cout << "\nBhe--" << endl;
//             // cout << n << endl;
//             // cout << k << endl;
//             // cout << fine << endl;
//             // cout << subsets.size() << endl;
//             set<Operator> subset = subsets[i];
//             // cout << "\n" << endl;
//             // cout << node.get_k() << endl;
//             // cout << "\n" << endl;
//             // cout << node.get_deactivated_op().size() << endl;
//             // cout << "\n" << endl;
//             // cout << subset.size() << endl;
//             // cout << "\n" << endl;
//             // cout << node.get_k() + (node.get_deactivated_op().size() - subset.size()) << endl;
//             // cout << "\n-------------------" << endl;
//             int k1 = node.get_k() + (node.get_deactivated_op().size() - subset.size());
//             // cout << "\nBhi" << endl;
//             deactivated_op_copy.insert(subset);
//             ResilientNode to_add = ResilientNode(node.get_state(), k1, deactivated_op_copy);
//             non_resilient_nodes.insert(make_pair(to_add.get_id(), to_add));
//             add_non_resilient_deadends(to_add);
//         }
//         cout << "\nFine" << endl;
//     }

//     // if (node.get_deactivated_op().size() != 0)
//     // {
        
//     //     vector<std::set<Operator> > subsets;
//     //     std::set<Operator> v_set = node.get_deactivated_op();
        
//     //     // copy original set into vector to apply bitmasking method to find the power set
//     //     vector<Operator> vec;
//     //     for (std::set<Operator>::iterator it = v_set.begin(); it != v_set.end(); it++)
//     //     {
//     //         Operator to_push = *it;
//     //         vec.push_back(to_push);
//     //     }
//     //     // vector<set<Operator> > subsets;
//     //     generatePowerSetInRange(vec, (node.get_k()+node.get_deactivated_op().size()-g_max_faults), subsets);
//     //     cout << subsets.size() << endl;
//     //     for (int i = 0; i < subsets.size(); i++)
//     //     {
//     //         // cout << "\nBhe--" << endl;
//     //         // cout << n << endl;
//     //         // cout << k << endl;
//     //         // cout << fine << endl;
//     //         // cout << subsets.size() << endl;
//     //         set<Operator> subset = subsets[i];
//     //         cout << "\n" << endl;
//     //         cout << node.get_k() << endl;
//     //         cout << "\n" << endl;
//     //         cout << node.get_deactivated_op().size() << endl;
//     //         cout << "\n" << endl;
//     //         cout << subset.size() << endl;
//     //         cout << "\n" << endl;
//     //         cout << node.get_k() + (node.get_deactivated_op().size() - subset.size()) << endl;
//     //         cout << "\n-------------------" << endl;
//     //         int k1 = node.get_k() + (node.get_deactivated_op().size() - subset.size());
//     //         // cout << "\nBhi" << endl;
//     //         ResilientNode to_add = ResilientNode(node.get_state(), k1, subset);
//     //         non_resilient_nodes.insert(make_pair(to_add.get_id(), to_add));
//     //         add_non_resilient_deadends(to_add);
//     //     }
        
//     // }
//     // cout << "\nFine" << endl;
//     return;
// }

/// @brief Update non resilient nodes with every <s,k',V'> such that V' is a subset of V and k' = k - |V \ V'|.
/// @param node Deadend node to insert in the list non-resilient nodes.
void update_non_resilient_nodes(ResilientNode node)
{
    non_resilient_nodes.insert(make_pair(node.get_id(), node));
    add_non_resilient_deadends(node);
    if (node.get_deactivated_op().size() != 0)
    {
        vector<std::set<std::set<Operator> > > subsets;
        std::set<std::set<Operator> > v_set = node.get_deactivated_op();

        // copy original set into vector to apply bitmasking method to find the power set
        vector<set<Operator> > vec;
        for (std::set<std::set<Operator> >::iterator it = v_set.begin(); it != v_set.end(); it++)
        {
            set<Operator> to_push = *it;
            vec.push_back(to_push);
        }

        // bit masking method for finding subsets
        int set_size = node.get_deactivated_op().size();
        int pow_set_size = pow(2, set_size);
        int counter, j;
        for (counter = 0; counter < pow_set_size; counter++)
        {
            set<set<Operator> > current;
            for (j = 0; j < set_size; j++)
                if (counter & (1 << j))
                    current.insert(vec[j]);
            subsets.push_back(current);
        }

        // add all <s,V',k'> with V' subset of V and k' = k - |V \ V'| to non-resilient set
        for (int i = 0; i < subsets.size() - 1; i++)
        {
            set<set<Operator> > subset = subsets[i];
            int k1 = node.get_k() + (node.get_deactivated_op().size() - subset.size());
            ResilientNode to_add = ResilientNode(node.get_state(), k1, subset);
            non_resilient_nodes.insert(make_pair(to_add.get_id(), to_add));
            add_non_resilient_deadends(to_add);
        }
    }
    return;
}



/// @brief Regress the state contained in node and add every state-action pair Regr(s,A)
/// to the fault model policy map indexed by the current (k,V).
/// @param node Node containing the state to regress and the current (k,V).
void add_non_resilient_deadends(ResilientNode node)
{
    State state = node.get_state();
    list<PolicyItem *> de_items;
    PartialState *dummy_state = new PartialState();

    PartialState *de_state = new PartialState(state);

    // Removed generalization in order to use other heuristics than FF and ADD.
    // Need to investigate further if it's useful for performance
    // and it will be worth to generalize to other heuristics.
    // generalize_deadend(*de_state);

    vector<PolicyItem *> reg_items;
    g_regressable_ops->generate_applicable_items(*de_state, reg_items, true, g_regress_only_relevant_deadends);

    for (int j = 0; j < reg_items.size(); j++)
    {
        RegressableOperator *ro = (RegressableOperator *)(reg_items[j]);
        de_items.push_back(new NondetDeadend(new PartialState(*de_state, *(ro->op), false, dummy_state),
                                             ro->op->nondet_index));
    }

    std::set<std::set<Operator> > deactivated_op = node.get_deactivated_op();

    // Set per raccogliere tutti gli Operator
    std::set<Operator> combined_set;

    // Iterazione attraverso deactivated_op
    for (std::set<std::set<Operator> >::const_iterator it = deactivated_op.begin(); it != deactivated_op.end(); ++it) {
        const std::set<Operator>& inner_set = *it;

        // Unione di inner_set con combined_set
        combined_set.insert(inner_set.begin(), inner_set.end());
    }

    delete dummy_state;
    Policy *current_deadend_policy = new Policy();
    
    if (g_non_resilient_deadends.find(std::make_pair(node.get_k(), combined_set)) != g_non_resilient_deadends.end()){
        current_deadend_policy = g_non_resilient_deadends[std::make_pair(node.get_k(), combined_set)];
    }
    current_deadend_policy->update_policy(de_items);
    g_non_resilient_deadends.insert(std::make_pair(std::make_pair(node.get_k(), combined_set), current_deadend_policy));


    std::set<Operator> combined_forbidden_ops;

    // Iterazione attraverso g_current_forbidden_ops
    for (std::set<std::set<Operator> >::const_iterator it = g_current_forbidden_ops.begin(); it != g_current_forbidden_ops.end(); ++it) {
        const std::set<Operator>& inner_set = *it;

        // Unione di inner_set con combined_forbidden_ops
        combined_forbidden_ops.insert(inner_set.begin(), inner_set.end());
    }
    g_non_resilient_deadends.insert(std::make_pair(std::make_pair(g_current_faults, combined_forbidden_ops), current_deadend_policy));



    std::set<Operator> v = combined_set;
    for (std::set<Operator>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::set<Operator> forbidden_minus_a = combined_forbidden_ops;
        forbidden_minus_a.erase(*it);

        Policy *s_a = new Policy();
        list<PolicyItem *> s_a_item;

        s_a_item.push_back(new NondetDeadend(new PartialState(state), it->nondet_index));

        if (g_non_resilient_deadends.find(std::make_pair(g_current_faults + 1, forbidden_minus_a)) != g_non_resilient_deadends.end())
            g_non_resilient_deadends.find(std::make_pair(g_current_faults + 1, forbidden_minus_a))->second->update_policy(s_a_item);
        else
        {
            s_a->update_policy(s_a_item);
            g_non_resilient_deadends.insert(std::make_pair(std::make_pair(g_current_faults + 1, forbidden_minus_a), s_a));
        }
    }
}


std::vector<Operator> FragileActions(const std::vector<Operator>& actions, const std::vector<std::string>& objects) {
    std::vector<Operator> fragileActions;

    // Itera attraverso gli operatori
    for (std::vector<Operator>::const_iterator it = actions.begin(); it != actions.end(); ++it) {
        const Operator& op = *it;
        // Ottieni la lista degli oggetti dell'operatore
        const std::vector<std::string>& objList = op.obj(); // Usa la funzione get_obj() invece di operator->obj()
        
        // Controlla se l'operatore agisce su uno degli oggetti specificati
        bool found = false;
        for (std::vector<std::string>::const_iterator objIt = objList.begin(); objIt != objList.end(); ++objIt) {
            const std::string& obj = *objIt;
            if (std::find(objects.begin(), objects.end(), obj) != objects.end()) {
                found = true;
                break;
            }
        }
        if (found) {
            fragileActions.push_back(op);
        }
    }

    return fragileActions;
}

std::vector<std::string> intersection(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    // Ordina entrambi i vettori per semplificare l'intersezione
    std::vector<std::string> sorted_vec1 = vec1;
    std::vector<std::string> sorted_vec2 = vec2;
    std::sort(sorted_vec1.begin(), sorted_vec1.end());
    std::sort(sorted_vec2.begin(), sorted_vec2.end());
    
    // Inizializza un vettore per memorizzare l'intersezione
    std::vector<std::string> result;
    
    // Utilizza std::set_intersection per trovare l'intersezione
    std::set_intersection(sorted_vec1.begin(), sorted_vec1.end(),
                          sorted_vec2.begin(), sorted_vec2.end(),
                          std::back_inserter(result));
    
    return result;
}

// Funzione principale per generare sottoinsiemi in un intervallo di dimensioni specifiche
void generatePowerSetInRange(vector<Operator>& vec, int minSize, vector<set<Operator> >& subsets) {
    // for (int k = maxSize-1; k >= minSize; --k) {
        // if(k == vec.size()-1){
            int64_t bitmask = (1UL << vec.size());
            bitmask = bitmask -1;
            int h=0;
            uint64_t differenza = 0;
            while (bitmask>0)
            {
                bitmask = bitmask + differenza;              
                    differenza = 1UL << h;
                    bitmask = bitmask - differenza;
                    if(bitmask>0){
                        cout << bitmask << endl;
                        set<Operator> subset;
                        for (uint64_t i = 0; i < vec.size(); ++i) {
                            if (bitmask & (1UL << i)) {  // Controlla se il bit i è impostato nel bitmask
                                subset.insert(vec[i]);
                            }
                            cout << subset.size() << endl;
                        }
                        subsets.push_back(subset);
                        cout << "--------------------------" << endl;
                        cout << subset.size() << endl;
                        cout << minSize << endl;
                        cout << "--------------------------" << endl;
                        if(subset.size() > minSize){
                            vector<Operator> subsetVec(subset.begin(), subset.end());
                            cout << subsetVec.size() << endl;
                            generatePowerSetInRange(subsetVec, minSize, subsets);
                        }
                        h=h+1;
                    }

                                    
                

            }
        // }
    // }
    cout << "lllllllllllllllllllllllllllllllllllllllllll" << endl;
    cout << subsets.size() << endl;
    // return subsets;
}

// Funzione per ottenere tutti gli elementi dai set interni
std::set<Operator> getElements(const std::set<std::set<Operator> >& outer_set) {
    std::set<Operator> all_elements;
    for (std::set<std::set<Operator> >::const_iterator outer_it = outer_set.begin(); outer_it != outer_set.end(); ++outer_it) {
        const std::set<Operator>& inner_set = *outer_it;
        for (std::set<Operator>::const_iterator inner_it = inner_set.begin(); inner_it != inner_set.end(); ++inner_it) {
            all_elements.insert(*inner_it);
        }
    }
    return all_elements;
}

