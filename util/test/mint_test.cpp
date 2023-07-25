#include "../mint.hpp"

int main() {
    mint m1 = mint(100);
    assert(m1.value() == 100);

    mint m2 = mint(1000000000);
    assert(m2.value() == 1755647);

    mint mp1 = mint(100) + mint(200);
    assert(mp1.value() == 300);

    mint mp2 = mint(500000000) + mint(700000000);
    assert(mp2.value() == 201755647);

    mint mm1 = mint(500) - mint(100);
    assert(mm1.value() == 400);

    mint mm2 = mint(100) - mint(200);
    assert(mm2.value() == 998244253);

    mint mmul1 = mint(200) * mint(300);
    assert(mmul1.value() == 60000);

    mint mmul2 = mint(200000) * mint(300000);
    assert(mmul2.value() == 105338820);

    mint md1 = mint(100) / mint(50);
    assert(md1.value() == 2);

    mint md2 = mint(7) / mint(25);
    assert(md2.value() == 239578645);

    mint md3 = mint(1) / mint(2);
    assert(md3.value() == 499122177);

    return 0;
}