#include "Asset.hpp"
#include "BaseAsset.hpp"
#include "AppreciatingAsset.hpp"
#include "DepreciatingAsset.hpp"
#include <cmath>
#include <iostream>

int main() {
    BaseAsset BA(100);
    BaseAsset BA1(100);
    AppreciatingAsset A(&BA, 10);
    DepreciatingAsset D(&A, 10);

    std::cout << A.getValue(1)
                << std::endl
                << A.getValue(1)
                << std::endl
                << D.getValue(1) << " "
                << D.getValue(1)
                << std::endl;


    return 0;
}