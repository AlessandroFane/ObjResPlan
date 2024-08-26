# Resilient Planner

## Build
```
./src/build_all
```

## Examples
```
src/resplanner benchmarks/domains/blocksworld/domain.pddl benchmarks/domains/blocksworld/pfile1.pddl --resilient 2 --verbose 1 --dump-resilient-nodes 1
src/resplanner benchmarks/navigation_typed/domain.pddl benchmarks/navigation_typed/problem.pddl --resilient 1 --verbose 1 
```

## Usage
```
./src/resplanner <domain> <problem> OPTIONS

--resilient K
    Number of maximum faults allowed

--verbose 1/0
    Verbose mode

--plan-to-file 1/0
    Dump the resilient plan to a file

--dump-resilient-nodes 1/0
    Print all resilient nodes found

```

