Project Deliverables (MVP)

- [x] BigInt struct
- [ ] binary operators (+,-,/,\*)
  - [ ] implement karatsuba algorithm for multiplication
- [x] relational operators (==, >=, <=)
- [ ] inplace-operators
- [x] unary operators (-)
- [ ] Make generic to integral types
- [ ] experiment with `std::to_chars` for str to vec<int> conversion

---

Things to benchmark

- Conversion operator vs handwritten specialization
- `std::vector<int>` vs `std::vector<char>` for container
- [x] representation for signed integer
- [ ] stringversion
- [ ] correctness of subtraction
