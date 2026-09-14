#include "shared_types.h"
#include <iostream>

using namespace std;

unique_ptr<Result> calculateB(shared_ptr<const InputData> data)
{
    cout << "[Student B] Processing data...\n";

    return make_unique<Result>(Result{ 0.0, 0.0 });
}