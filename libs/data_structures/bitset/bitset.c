# include <stdio.h>
# include <assert.h>
# include "bitset.h"
# include <stdbool.h>


int bitset_checkValue ( bitset *a , unsigned value ) {
    return value >= 0 && value <= a -> maxValue ;
}


bitset bitset_create ( unsigned setMaxValue ) {
    assert ( setMaxValue < 32) ;
    return ( bitset ) {0 , setMaxValue };
}


bool bitset_in ( bitset set , unsigned value ) {
    if ((set.values >> value) & 1)
        return true;
    else
        return false;
}


bool bitset_isEqual ( bitset set1 , bitset set2 ) {
    if (set1.values == set2.values) 
        return true;
    else
        return false;
}


bool bitset_isSubset ( bitset subset , bitset set ) {
    if (((set.values & subset.values) == subset.values) && (subset.values != set.values))
        return true;
    else
        return false;
}


void bitset_insert ( bitset * set , unsigned value ) {
    set->values = set->values | (1 << value);
}


void bitset_deleteElement ( bitset * set , unsigned value ) {
    set->values = set->values & ~(1 << value);
}


bitset bitset_union ( bitset set1 , bitset set2 ) {
    bitset output_set = bitset_create(set1.maxValue);
    output_set.values = set1.values | set2.values;
    return output_set;
}


bitset bitset_intersection ( bitset set1 , bitset set2 ) {
    bitset output_set = bitset_create(set1.maxValue);
    output_set.values = set1.values & set2.values;
    return output_set;
}


bitset bitset_difference ( bitset set1 , bitset set2 ) {
    bitset output_set = bitset_create(set1.maxValue);
    output_set.values = set1.values & ~set2.values;
    return output_set;
}

bitset bitset_symmetricDifference ( bitset set1 , bitset set2 ) {
    bitset output_set = bitset_create(set1.maxValue);
    output_set.values = set1.values ^ set2.values;
    return output_set;
}


bitset bitset_complement ( bitset set ) {
    uint32_t useless_bits = 31 - set.maxValue;
    bitset output_set = bitset_create(set.maxValue);
    output_set.values = ((~set.values) << useless_bits) >> useless_bits;
    return output_set;
}


void bitset_print ( bitset set ) {
    int is_first_element = true;
    printf("{");

    for (int i = 0; i < set.maxValue; i++) {
        if (bitset_in(set, i)) {
            if (is_first_element) {
                printf("%d", i);
                is_first_element = false;
            }
            else
                printf(", %d", i);
        }
    }

    printf("}\n");
}