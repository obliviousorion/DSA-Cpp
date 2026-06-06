# DSA CPP Workspace

Purpose
- Minimal, disciplined workspace for solving algorithmic problems in C++.
- Write solutions in `main.cpp`, use `input.txt`/`output.txt` for I/O, and let Copilot (or manual saves) archive cleaned solutions in an organized layout.

Quickstart
1. Clone the repository.
2. Create `input.txt` with the problem input.
3. Create an empty `output.txt` (optional — used to capture program output).
4. Implement your solution in `main.cpp`.

Tagging rules (required for automatic archiving)
- At the top of `main.cpp` include the following exact comment lines:

  // Section : <Section Name>

  // Problem : <Problem Title>

- Example:

  // Section : Binary Search
  // Problem : Minimum Rotations for Sorted Array

Automatic saving behavior
- Use the workspace prompt `/save-dsa` and Copilot helper to extract and save the core solution.
- Saved files will be placed under `Archive/[Section]/` and named using the problem title converted to snake_case (spaces → underscores, lowercased). Example:

  `Archive/Binary Search/minimum_rotations_for_sorted_array.cpp`

File expectations
- Keep `main.cpp` focused: include the solution class/functions and a minimal `main()` driver for local testing.
- Avoid committing large input files; keep `input.txt` small for examples and tests.

Run locally
- If a `run` helper script exists, use it. Otherwise compile and run manually:

```bash
g++ -std=c++17 main.cpp -O2 -o main
./main < input.txt > output.txt
```

Recommended workflow
1. Implement and test locally using `input.txt` / `output.txt`.
2. Add the required `// Section :` and `// Problem :` tags in `main.cpp`.
3. Use the Copilot workspace command or provided prompt to extract and archive the solution.

Directory layout (relevant paths)
- `main.cpp` — active editing file for new solutions.
- `input.txt`, `output.txt` — local test I/O.
- `Archive/<Section>/` — canonical storage for cleaned solutions.

Notes
- The archiving tool looks for exact tag prefixes; ensure spacing and capitalization match `// Section :` and `// Problem :`.
- If a target file already exists under `Archive/<Section>/`, the archiver will prompt before overwriting — verify tags if you see that prompt.

License
- No license specified. Add one if you intend to publish.
