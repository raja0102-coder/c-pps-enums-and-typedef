#include <stdio.h>

// 1. Defining an enumeration for Days of the Week with typedef
typedef enum {
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;

// 2. Defining an enumeration for application error codes and statuses
typedef enum {
    STATUS_SUCCESS = 0,
    STATUS_ERROR_INVALID_INPUT = -1,
    STATUS_ERROR_OUT_OF_BOUNDS = -2
} Status;

// Function returning a Status enum based on validation
Status validateAge(int age) {
    if (age < 0 || age > 130) {
        return STATUS_ERROR_INVALID_INPUT;
    }
    return STATUS_SUCCESS;
}

int main() {
    printf("==================================================\n");
    printf("      PPS ENUMERATIONS & TYPEDEF ENGINE           \n");
    printf("==================================================\n\n");

    // 1. Using Enum with Typedef
    printf("[1] ENUMERATION & TYPEDEF DEMONSTRATION:\n");
    Day today = WEDNESDAY;
    printf("    Assigned Day Enum Value: %d\n", today);

    switch (today) {
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
        case FRIDAY:
            printf("    Status: It's a weekday. Time to write C code!\n\n");
            break;
        case SATURDAY:
        case SUNDAY:
            printf("    Status: It's the weekend! Time to relax.\n\n");
            break;
        default:
            printf("    Status: Unknown day.\n\n");
    }

    // 2. Function returning Enum Status
    printf("[2] FUNCTION RETURNING ENUM STATUS CODES:\n");
    int testAges[] = {19, -3, 140};
    for (int i = 0; i < 3; i++) {
        Status res = validateAge(testAges[i]);
        if (res == STATUS_SUCCESS) {
            printf("    Age %3d -> STATUS_SUCCESS (%d)\n", testAges[i], res);
        } else {
            printf("    Age %3d -> STATUS_ERROR_INVALID_INPUT (%d)\n", testAges[i], res);
        }
    }

    printf("\n==================================================\n");

    return 0;
}
