add_library(data_structures
bitset/bitset.c
unordered_set/unordered_array_set.c
ordered_set/ordered_array_set.c
vector/vector.c
vector/vectorVoid.c
matrix/matrix.c
string/string_.c
files/file_lib.c)


target_link_libraries(data_structures algorithms)
