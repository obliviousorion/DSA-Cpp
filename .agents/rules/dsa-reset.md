---
trigger: always_on
---

# Antigravity Workspace Rule: Core DSA Slate Clean & Reset Pipeline

## Purpose
You are an automated workspace reset and initialization agent. Your job is to clear the current C++ scratchpad (`main.cpp`), reset the template, and optionally initialize a new problem structure when metadata or problem details are provided.

## Instructions & Workflow

1. **Slate Cleaning (Reset):**
   - Clear the contents of the main scratchpad file (`./main.cpp` relative to the workspace root, mapped dynamically to the absolute path of the current host OS).
   - Clear/reset `./input.txt` and `./output.txt` (to prevent stale input/output runs, write a single newline character `\n` to avoid validation errors with empty strings in editor tools).

2. **Template Initialization:**
   - Populated the clean `main.cpp` with the following standard layout:
     ```cpp
     #include <bits/stdc++.h>
     using namespace std;

     // Section : [Section Name]
     // Problem : [Problem Title]

     class Solution {
     public:
         // Write solution logic here
     };

     int main() {
         // Fast I/O
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);

         // Write driver code here

         return 0;
     }
     ```

3. **Metadata Enrichment & Problem Setup:**
   - If the user provides a section name, problem title, description, or link for the next problem:
     - **Handle Vague/Loose Prompts:** If the user provides loose or incomplete information (e.g., a vague name, a partial description, or a raw link), autonomously search or infer the missing details (such as the standard Section Name, formal Problem Title, correct C++ LeetCode signature, and helper driver code) to set everything up without requiring the user to be highly specific.
     - Replace `[Section Name]` and `[Problem Title]` in the template with the provided or resolved metadata.
     - Extract/infer the signature of the solution class and target method (e.g., from LeetCode, web search, or a user prompt) and populate the `Solution` class.
     - Provide a basic `main()` driver that reads example input format if it can be inferred, or leave standard placeholder input reading.
   - If example test cases are provided, populate `input.txt` with the sample input so it is ready for execution.

4. **Completion Summary:**
   - Display a brief, concise summary of the initialized problem structure to the user, pointing out that the slate has been cleared and the template is ready.
