# Unordered Map

`hash_map` has not been added into _C++11_. Instead, we can use `unordered_map` to store _(key,value)_ pairs:

```c++
template < class Key,                                    // unordered_map::key_type
           class T,                                      //unordered_map::mapped_type
           class Hash = hash<Key>,                       // unordered_map::hasher
           class Pred = equal_to<Key>,                   // unordered_map::key_equal
           class Alloc = allocator< pair<const Key,T> >  // unordered_map::allocator_type
           > class unordered_map;
```

In an `unordered_map`, the key value is generally used to uniquely identify the element, while the mapped value is an object with the content associated to this key. Types of key and mapped value may differ.

1. Insert: Use `[]` or `map.insert(element)`
2. Find: Use `[]` or `map.find(element)`
3. Erase: `map.erase(key)`
