#include "../src/value.h"
#include "../functions/func_headers.h"
#include <cassert>

bool test_semantic_tabulax_valid(){
    using namespace std;
    Value p(ValType::Operand, "p");
    Value q(ValType::Operand, "q");
    Value or_opt(ValType::Operator, "or");
    Value not_opt(ValType::Operator, "not");

    // proofing p V q, ~p |= q is valid
    vector<Value> premise1{p, q, or_opt};
    vector<Value> premise2{p, not_opt};
    vector<Value> conclusion{q};

    vector<vector<Value>> premise_conc{premise1, premise2, conclusion};

    return sematic_tabulax(premise_conc);
}

bool test_semantic_tabulax_invalid(){
    using namespace std;
    Value p(ValType::Operand, "p");
    Value q(ValType::Operand, "q");
    Value or_opt(ValType::Operator, "or");

    // proofing p V q, p |= q is invalid
    vector<Value> premise1{p, q, or_opt};
    vector<Value> premise2{p};
    vector<Value> conclusion{q};

    vector<vector<Value>> premise_conc{premise1, premise2, conclusion};

    return sematic_tabulax(premise_conc);
}

int main() {
    using namespace std;

    assert(test_semantic_tabulax_valid() == true);
    assert(test_semantic_tabulax_invalid() == false);


}
