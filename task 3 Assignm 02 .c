#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void updateSectorStatus(int grid[ROWS][COLS]);
void querySectorStatus(int grid[ROWS][COLS]);
void runSystemDiagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;

    do {
        printf("\n===== IESCO Power Grid Monitoring System =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSectorStatus(grid);
                break;
            case 2:
                querySectorStatus(grid);
                break;
            case 3:
                runSystemDiagnostic(grid);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to update a sector's status
void updateSectorStatus(int grid[ROWS][COLS]) {
    int row, col, flag, action;

    printf("Enter sector coordinates (row and column): ");
    scanf("%d %d", &row, &col);

    if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nSelect Flag to Update:\n");
    printf("0. Power Status\n");
    printf("1. Overload Warning\n");
    printf("2. Maintenance Required\n");
    printf("Enter flag number: ");
    scanf("%d", &flag);

    printf("Enter action (1 = Set / 0 = Clear): ");
    scanf("%d", &action);

    if (action == 1)
        grid[row][col] |= (1 << flag);   // Set bit
    else
        grid[row][col] &= ~(1 << flag);  // Clear bit

    printf("Sector [%d][%d] updated successfully!\n", row, col);
}

// Function to query sector status
void querySectorStatus(int grid[ROWS][COLS]) {
    int row, col, status;

    printf("Enter sector coordinates (row and column): ");
    scanf("%d %d", &row, &col);

    if (row >= ROWS || col >= COLS || row < 0 || col < 0) {
        printf("Invalid coordinates!\n");
        return;
    }

    status = grid[row][col];
    printf("\nStatus for Sector [%d][%d]:\n", row, col);
    printf("Power: %s\n", (status & 1) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & (1 << 1)) ? "Overloaded" : "Normal");
    printf("Maintenance: %s\n", (status & (1 << 2)) ? "Required" : "Not Required");
}

// Function to run system diagnostic
void runSystemDiagnostic(int grid[ROWS][COLS]) {
    int overloadCount = 0, maintenanceCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & (1 << 1))
                overloadCount++;
            if (grid[i][j] & (1 << 2))
                maintenanceCount++;
        }
    }

    printf("\n===== System Diagnostic Report =====\n");
    printf("Total Overloaded Sectors: %d\n", overloadCount);
    printf("Total Sectors Requiring Maintenance: %d\n", maintenanceCount);
}

