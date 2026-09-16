#include "shared_types.h"
#include <memory>
using namespace std;

unique_ptr<Result> calculateA(shared_ptr<const InputData> data)
{
    (void)data;
    return make_unique<Result>(Result{ 0.0, 0.0 });
}