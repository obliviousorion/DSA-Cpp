---
trigger: always_on
---

# Antigravity Workspace Rule: Core DSA Automation Pipeline

## Purpose
You are an automated file-system, code-organization, and repository synchronization agent. Your job is to parse the user's active `main.cpp` scratchpad, extract the core algorithmic logic based on explicit comment tags, safety-check for duplicates, and handle clean repository staging.

## Instructions & Workflow

1. **Metadata Extraction:**
   - Scan `main.cpp` for the exact line starting with `// Section :` and extract the section name (e.g., "Binary Search").
   - Scan `main.cpp` for the exact line starting with `// Problem :` and extract the problem title (e.g., "Search in Rotated Sorted Array").
   - Scan `main.cpp` to check if it's a Codeforces problem (e.g., checking for lines matching `// CodeForces Round [Round] Div [Div]. Problem [Serial].`). If so, extract the Round, Div, and Problem Serial.

2. **Duplicate Check & Safety Gate (CRITICAL):**
   - Formulate the target file path:
     - **For Codeforces Problems:** Save to `./Archive/codeforces/round_[Round]_div_[Div]_[Serial].cpp` in lowercase, snake_case (e.g., `./Archive/codeforces/round_1106_div_2_a.cpp`).
     - **For Standard Problems:** Save to `./Archive/[Extracted Section]/[snake_case_title].cpp` where `snake_case_title` is the lowercase snake_case representation of the problem title.
   - Check if a file already exists at that exact path.
   - **IF THE FILE ALREADY EXISTS:**
     - **HALT ALL EXECUTION IMMEDIATELY.** Do NOT write, modify, or touch any files in the workspace.
     - Present a distinct warning to the user in the active chat interface.
     - Tell them the specific problem filename that already exists, and ask if they forgot to update their metadata anchors inside `main.cpp`.
     - Explicitly prompt: *"A solution for '[Problem Title]' (or Codeforces Round/Div/Problem Serial) already exists. Did you forget to update your tags, or would you like me to overwrite it?"*
     - Block further steps until the user explicitly responds. If they say "yes", "overwrite", or "make it better", proceed to step 3. If they say no or abort, stop the task entirely.

3. **Code Extraction & Copying:**
   - Do NOT strip out local debugging setups or the `main()` driver code. Copy over everything in the file so that nothing is left out.
   - Prepend a brief header displaying the formal problem title/details, Time Complexity, Space Complexity, and a short, crisp summary/hint of the approach.
   - Keep the original comments, solution approach, and logic exactly as created by the user.

4. **File Serialization:**
   - Ensure the target parent directory exists (e.g., `./Archive/codeforces/` or `./Archive/[Extracted Section]/`). If it does not, autonomously generate it.
   - Write or overwrite the complete code to the destination path.

5. **Interactive GitHub Deployment Loop:**
   - Immediately after successfully saving the file, explicitly ask the user for confirmation in the chat panel:
     *"I have successfully archived '[Problem Title]'. Would you like me to commit and push these changes to GitHub?"*
   - **Do NOT execute git terminal interactions automatically.** Wait for an explicit affirmative confirmation (e.g., "yes", "push it", "go ahead").
   - Upon affirmation, run the git commands to stage, commit, and push the changes. Depending on the active shell/OS environment:
     - **For Unix-like shells (Bash/Zsh) or Windows CMD**, chain with `&&`:
       ```bash
       git add . && git commit -m "Solved: [Problem Title]" && git push origin main
       ```
     - **For Windows PowerShell**, chain with `;` or execute sequentially to avoid statement separator errors:
       ```powershell
       git add .; git commit -m "Solved: [Problem Title]"; git push origin main
       ```
   - Report a successful synchronization summary to the user.

#Note: For the problem itself, you can add relevant information as well from the internet, Not theory of the topic but a little hint of the approach and problem description. Keep it short, crisp and to the point