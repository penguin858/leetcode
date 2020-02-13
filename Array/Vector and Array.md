# Vector and Array in C++

_Sequence_, which is the simplest _Linear Data Structure_, can be divided into _Vector_, _Array_ and _List_. They arrange the data into a sequence and follow some sort of order, which results in some questions about sorting(Will be discuss in other documents).

C++ defines Array as a basic data type, Vector and List in _Standard Template Libraries_(STL).

## 1. Common Interfaces of Vector

|Interfaces | Functions |
| --- | --- |
| size() | returns the number of elements |
| [pos] | access specified element |
| at(pos) | access specified element with bound check | 
| [insert(iterator, value)](https://en.cppreference.com/w/cpp/container/vector/insert) | Inserts elements at the specified location in the container.| 
|emplace(iterator, args) _(after c++11)_ | Construct and inserts a new element into the container directly before iterator's position.|
|push\_back(value) | Appends the given element value to the end of the container.|
|pop\_back() | Removes the last element of the container.|
|empty()|Checks whether the container is empty |
|erase(iterator) | Remove the specified element(s) from container.|

## 2. Performance - Amortized Complexity

Vector is defined as an expandable data structure. The standard guarantees that vector::push_back has amortized **O(1)** complexity. That means if you look at a sufficiently large number of calls to push_back, the number of operations for each approaches a constant.

_Amortized Complexity_ is totally different from _Average Complexity_. The former refers to amortizing the total running time to a real operation sequence, while the latter refers to the latter represents a weighted average of the execution time required in each case according to some assumed probability distribution.
