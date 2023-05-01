universal_set = {1, 2, 3, 4, 5}
subsets = {
    frozenset({1, 2, 3}): 1,        
    frozenset({4, 5}): 1,
    frozenset({4, 1, 3}): 5,
    frozenset({2, 5}): 10,
    frozenset({1, 4, 3, 2}): 3
}

def set_cover_problem(universal_set, subsets):
    uncovered = universal_set
    selected_subsets = []
    minimum_cost = 0
    
    while uncovered:
        best_subset = max(subsets, key=lambda s: (s & uncovered))
        print("Best Subset",best_subset)
        uncovered -= best_subset
        selected_subsets.append(set(best_subset))
        minimum_cost += subsets[best_subset]
        del subsets[best_subset] 
    return selected_subsets, minimum_cost

selected_subsets, minimum_cost = set_cover_problem(universal_set, subsets)
print("Minimum subset cost = ", minimum_cost)
print("Selected cost = ", selected_subsets)