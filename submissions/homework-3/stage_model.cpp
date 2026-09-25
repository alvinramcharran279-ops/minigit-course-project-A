#include <iostream>
#include <string>

// A small subset of simple-minigit/examples/file_state_machine.cpp.
// "(missing)" is a teaching label, not real file-existence handling.
struct FileState {
    std::string working;
    std::string staged;
    std::string committed;
};

// Input: one initialized file state.
// Pre-condition: all three labels have values.
// Post-condition: staged copies working; working and committed are unchanged.
void stageWorkingCopy(FileState& fileState) {
    fileState.staged = fileState.working;
}


// Input: one condition and its name.
// Outcome: print PASS or FAIL and return 0 for pass, 1 for fail.
int check(bool condition, const std::string& name) {
    std::cout << (condition ? "PASS: " : "FAIL: ") << name << '\n';
    return condition ? 0 : 1;
}

int main() {
    FileState fileState{"ONE", "(missing)", "(missing)"};
    int failures = 0;
    failures += check(fileState.working == "ONE" &&
                          fileState.staged == "(missing)" &&
                          fileState.committed == "(missing)",
                      "before add: only working has ONE");
    stageWorkingCopy(fileState);
    failures += check(fileState.working == "ONE" &&
                          fileState.staged == "ONE" &&
                          fileState.committed == "(missing)",
                      "first add copies ONE to stage");
    fileState.working = "TWO";
    failures += check(fileState.working == "TWO" &&
                          fileState.staged == "ONE" &&
                          fileState.committed == "(missing)",
                      "editing working content leaves staged ONE");
    stageWorkingCopy(fileState);
    failures += check(fileState.working == "TWO" &&
                          fileState.staged == "TWO" &&
                          fileState.committed == "(missing)",
                      "second add copies TWO to stage");
      fileState.working = "THREE";
    failures += check(fileState.working == "THREE" &&
                          fileState.staged == "TWO" &&
                          fileState.committed == "(missing)",
                      "editing working again leaves staged TWO");
    std::cout << failures << " failed check(s)\n";
    return failures == 0 ? 0 : 1;
}
