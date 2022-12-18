#include <gtest/gtest.h>
#include "../../lib/deque.h"
using namespace custom_std;
TEST(CUSTOM_DEQUE,check_size)
{
    custom_deque<int> dq(3);
    EXPECT_EQ(dq.size(),3);
}
TEST(CUSTOM_DEQUE,check_empty)
{
    custom_deque<int> dq;
    EXPECT_EQ(dq.empty(), true);

}
TEST(CUSTOM_DEQUE,check_clear)
{
    custom_deque<int> dq={3,2,1};
    dq.clear();
    EXPECT_EQ(dq.size(), 0);

}
TEST(CUSTOM_DEQUE,check_constructor_list)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    EXPECT_EQ(dq.size(), 5);

}
TEST(CUSTOM_DEQUE,check_resize)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    dq.resize(6);

    EXPECT_EQ(dq.size(), 6);
    EXPECT_EQ(dq[dq.size()-1], 0);

}
TEST(CUSTOM_DEQUE,check_resize2)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    dq.resize(6,1);
    EXPECT_EQ(dq.size(), 6);
    EXPECT_EQ(dq[dq.size()-1],1);


}
TEST(CUSTOM_DEQUE,check_begin_end)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    custom_deque<int> dq2;
    for (int it : dq)
    dq2.push_back(it);
    EXPECT_EQ(dq.size(),dq2.size());

}
TEST(CUSTOM_DEQUE,check_cbegin_cend)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });

    EXPECT_EQ(*dq.cbegin(),1);
    auto iter1=*dq.end();
    auto iter2=*dq.cend();
    EXPECT_EQ(iter1,iter2);

}
TEST(CUSTOM_DEQUE,check_assign)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });

    dq.assign({ 21, 22, 23, 24, 25 });
    custom_deque<int> dq2=dq;
    dq.assign(4, 3);
    dq.assign({1,2,3,4});
    for (int i=1 ,j=0;j<dq.size()&&i<5;j++,++i)
    {
        EXPECT_EQ(dq[j],i);
    }


}
TEST(CUSTOM_DEQUE,check_swap)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    custom_deque<int> dq2({  2, 3, 4, 5 });
    dq.swap(dq2);
    for (int i=2 ,j=0;j<dq.size()&&i<5;j++,++i)
    {
        EXPECT_EQ(dq[j],i);
    }



}





TEST(CUSTOM_DEQUE,check_at)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    int el=dq.at(0);
    int el2=dq[0];
    bool check= el==el2;
    EXPECT_EQ(check,true);
    const int el3=dq[1];
    EXPECT_EQ(el3,2);


}

TEST(CUSTOM_DEQUE, check_back)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    ASSERT_EQ(dq.back(), 5);
    dq.pop_back();
    ASSERT_EQ(dq.back(), 4);
}

TEST(CUSTOM_DEQUE, check_op_equal)
{
    custom_deque<int> dq({ 1, 2, 3, 4, 5 });
    custom_deque<int> dq_2({1, 2, 3, 4, 5});
    custom_deque<int> dq_3({1, 2, 3, 4, 6});
    custom_deque<int> dq_4({1, 2, 3, 4, 5, 6});
    ASSERT_TRUE(dq == dq_2);
    ASSERT_FALSE(dq_2 == dq_3);
    ASSERT_FALSE(dq_2 == dq_4);
}

int main(int argc, char **argv) {

    return RUN_ALL_TESTS();
}

