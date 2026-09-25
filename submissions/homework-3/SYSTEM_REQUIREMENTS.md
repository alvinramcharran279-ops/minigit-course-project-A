## Approved UN/UR Baseline

## User needs

| ID | Stakeholder need |
|---|---|
| UN-GIT-01 | A student developer needs a way to start tracking a local project because it has no recorded history. |
| UN-GIT-02 | A student developer needs to know which project files have changed because they may forget what they edited before recording a checkpoint. |
| UN-GIT-03 | A student developer needs to inspect changed content before recording it because a file may contain unintended edits. |
| UN-GIT-04 | A student developer needs to choose the file content to include in the next checkpoint because later edits may still be unfinished. |
| UN-GIT-05 | A student developer needs to record a meaningful checkpoint because they want to preserve a known project state and explain its purpose. |
| UN-GIT-06 | A student developer needs to review earlier checkpoints because they want to understand how the project reached its current state. |
| UN-GIT-07 | A student developer needs invalid commands to explain why they failed while preserving existing project files and recorded checkpoints. |

## User requirements

| ID | User-visible capability | Need |
|---|---|---|
| UR-GIT-01 | A student developer shall be able to initialize tracking in the current local project folder without removing existing project files. | UN-GIT-01, UN-GIT-07 |
| UR-GIT-02 | A student developer shall be able to see whether project files are untracked, staged, changed after staging, modified, deleted, or clean. | UN-GIT-02 |
| UR-GIT-03 | A student developer shall be able to view differences between current working file content and the content selected for the next checkpoint. | UN-GIT-03 |
| UR-GIT-04 | A student developer shall be able to view differences between content selected for the next checkpoint and the latest recorded checkpoint. | UN-GIT-03 |
| UR-GIT-05 | A student developer shall be able to select the current content of one existing project file for the next checkpoint without selecting unrelated files. | UN-GIT-04 |
| UR-GIT-06 | A student developer shall be able to create a checkpoint of selected content with a nonempty explanation while leaving later unselected edits in the working files. | UN-GIT-05, UN-GIT-04 |
| UR-GIT-07 | A student developer shall be able to view recorded checkpoints from newest to oldest, including their identifier and explanation. | UN-GIT-06 |
| UR-GIT-08 | A student developer shall receive a useful error when a command is invalid, a requested file is unavailable, or a path is outside the allowed project files. | UN-GIT-07 |
| UR-GIT-09 | A student developer shall be able to retry an operation after a failure without losing ordinary project files or an already recorded checkpoint. | UN-GIT-07 |

## UR-to-UN Mapping

| UR ID | Source UN ID(s) |
|---|---|
| UR-GIT-01 | UN-GIT-01, UN-GIT-07 |
| UR-GIT-02 | UN-GIT-02 |
| UR-GIT-03 | UN-GIT-03 |
| UR-GIT-04 | UN-GIT-03 |
| UR-GIT-05 | UN-GIT-04 |
| UR-GIT-06 | UN-GIT-05, UN-GIT-04 |
| UR-GIT-07 | UN-GIT-06 |
| UR-GIT-08 | UN-GIT-07 |
| UR-GIT-09 | UN-GIT-07 |

## Functional System Requirements

SR-01 (source UR-GIT-01): Given an empty folder, when init is used, MiniGit shall create a new repository with all necessary tracking structures in that folder, with nothing yet tracked.
Check: inspect the folder for the new tracking structure and confirm status reports nothing tracked.

SR-02 (source UR-GIT-01): Given an already-initialized project with a staged notes.txt and one recorded checkpoint, when init is used again, MiniGit shall leave the existing stage and recorded checkpoint unchanged and shall not remove any existing project files.
Check: inspect the stage and checkpoint log before and after the second init to confirm both are unchanged.

SR-03 (source UR-GIT-05): Given an initialized project with notes.txt containing ONE and plan.txt present, when add notes.txt is used, MiniGit shall stage a copy of notes.txt containing ONE without staging plan.txt.
Check: inspect the stage for notes.txt (ONE) and confirm plan.txt is absent from the stage.

SR-04 (source UR-GIT-08, UR-GIT-09): Given a staged notes.txt containing ONE and missing.txt does not exist in the project, when add missing.txt is used, MiniGit shall report an error identifying missing.txt as not found and shall leave the staged notes.txt content ONE unchanged.
Check: inspect the error output and confirm the staged notes.txt content is still ONE.

SR-05 (source UR-GIT-02): Given an initialized project where notes.txt has been staged with content ONE, when status is used, MiniGit shall report notes.txt as staged and shall not report it as untracked or modified.
Check: inspect the status output for notes.txt listed under staged, not under untracked or modified.
