/*
 * File:   SimpleListTest.c
 * Author: Richard
 *
 * Created on Jan 29, 2017, 1:48:36 PM
 */

#include <CUnit/Basic.h>
#include "../SimpleList.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}
void str_print prints_the_data {
    printf("%s", (string)data);
}

void testGet_list() {
    Iter* testList = get_list();
    
    CU_ASSERT_TRUE(testList != 0);
    CU_ASSERT_PTR_EQUAL(testList->head_ptr, testList->tail_ptr);
    CU_ASSERT_PTR_EQUAL(testList->head_ptr->data_ptr, 0);
    CU_ASSERT_PTR_EQUAL(testList->head_ptr->next_ptr, 0);
    CU_ASSERT_EQUAL(testList->length, 0);
}

void testAdd() {
    Iter* testList = get_list();
    string testData1 = "Test Data1";
    string testData2 = "Test Data2";
    string testData3 = "Test Data3";
    
    add(testList, testData1);
    add(testList, testData2);
    add(testList, testData3);
    
    Node* head = testList->head_ptr;
    Node* tail = testList->tail_ptr;
    CU_ASSERT_PTR_EQUAL(testData1, head->data_ptr);
    CU_ASSERT_PTR_EQUAL(testData3, tail->data_ptr);
    CU_ASSERT_EQUAL(testList->length, 3);
}

void testDequeue() {
    
}

void testClear_list() {
    
}

void testClear() {
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("SimpleListTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testGet_list", testGet_list)) ||
            (NULL == CU_add_test(pSuite, "testAdd", testAdd)) ||
            (NULL == CU_add_test(pSuite, "testDequeue", testDequeue)) ||
            (NULL == CU_add_test(pSuite, "testClear_list", testClear_list)) ||
            (NULL == CU_add_test(pSuite, "testClear", testClear))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
