*This project has been created as part of the 42 curriculum by ybedrane, <partner_login>.*

## Description

`push_swap` sorts a stack of integers using two stacks (`a` and `b`) and only the authorized operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

This implementation includes all mandatory strategy classes required by the subject:
- Simple strategy (`O(n^2)` in push_swap operation model)
- Medium strategy (`O(n*sqrt(n))` in push_swap operation model)
- Complex strategy (`O(n log n)` in push_swap operation model)
- Adaptive strategy that selects the method based on input disorder

## Instructions

### Build

```bash
make
```

### Run

```bash
./push_swap [--bench] [--simple|--medium|--complex|--adaptive] <list of integers>
```

Examples:

```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23
./push_swap --bench --adaptive 4 67 3 87 23
```

### Flags

- `--adaptive` (default): choose algorithm from disorder metric
- `--simple`: force `O(n^2)` strategy
- `--medium`: force `O(n*sqrt(n))` strategy
- `--complex`: force `O(n log n)` strategy
- `--bench`: print benchmark metrics on stderr

### Error behavior

Prints `Error` on stderr for invalid integers, overflow, duplicates, or malformed input.

## Algorithm Details

### Disorder metric

Before sorting, disorder is measured as inversion ratio:

- `disorder = mistakes / total_pairs`
- where a mistake is any pair `(i, j)` with `i < j` and `a[i] > a[j]`

Range is `[0, 1]`:
- `0` means already sorted
- `1` means fully reversed

### Strategy rationale

- Low disorder (`< 0.2`): use simple extraction approach (`O(n^2)`)
- Medium disorder (`>= 0.2` and `< 0.5`): use chunked push/restore (`O(n*sqrt(n))`)
- High disorder (`>= 0.5`): use binary radix (`O(n log n)`)

These thresholds are chosen to keep overhead low on nearly sorted inputs while scaling better for highly disordered inputs.

### Space complexity

All strategies use linear auxiliary storage at most (`O(n)`), mainly for stack buffers and rank mapping.

## Group Contributions

- `ybedrane`: parsing, stack operations, benchmark mode, strategy integration
- `<partner_login>`: algorithm tuning, test cases, checker validation, documentation review

## Resources

- 42 subject for `push_swap`
- Donald Knuth, *The Art of Computer Programming* (sorting foundations)
- Visualgo and algorithm animation resources for stack/radix intuition

### AI usage

AI assistance was used for:
- Project scaffolding and file organization
- Explaining and cross-checking algorithm choices
- Drafting documentation structure

All generated code was reviewed, adjusted, and tested by learners before use.
