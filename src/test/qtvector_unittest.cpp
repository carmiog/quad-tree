#include <cmath>
#include <gtest/gtest.h>
#include "../qtvector.h"

TEST (QTVector, norm2) {
    QTVector qv{2, 2};
    ASSERT_FLOAT_EQ(sqrt(8), qv.norm2());
}
