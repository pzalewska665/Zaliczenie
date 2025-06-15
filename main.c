#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 20

typedef struct {
    char *task;
    int completed; // 1 - done, 0 - false
} Task;

Task *tasks = NULL;
int length = 0;

void addTask(const char *task) {
    if (length >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task)); // realloc - changing the size of the block
    tasks[length].task = (char *)malloc(strlen(task) + 1); // malloc - allocation of data
    tasks[length].completed = 0;

    strcpy(tasks[length].task, task);
    length++;
    printf("Task added\n");
}

void listTasks() {
    char status;
    for (int i = 0; i < length; i++) {
        if (tasks[i].completed == 1) {
            status = 'd'; //done

        }else {
            status = 'n';//not done
        }
        printf("%d. %s [%c]\n", i+1, tasks[i].task, status);
    }
}


void markCompleted(int index) {
    if (index <= length && index > 0) {
        tasks[index - 1].completed = 1;
        printf("Task completed\n");



    }else {
        printf("Task not completed\n");
    }
}



void deleteTask(int index) {
    if (index <= length && index > 0) {
        index = index - 1;

        free(tasks[index].task);

        for (int i = index; i < length - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        length--;
        tasks = (Task *)realloc(tasks, (length * sizeof(Task)));

    } else {
        printf("Invalid index\n");
    }
}


void editTask(int index, const char *task) {
    if (index <= length && index > 0) {
        index = index - 1;
        char *editTask = (char *)realloc(tasks[index].task, strlen(task) + 1);
        if (editTask != NULL) {
            tasks[index].task = editTask;
            strcpy(tasks[index].task, task);
            printf("Task edited\n");
        }else {
            printf("Memory allocation failed\n");
        }


    }else {
        printf("Invalid index\n");
    }
}

void saveTasksToTheFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("File could not be opened\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        fprintf(file, "%d;%s\n", tasks[i].completed, tasks[i].task);

    }
    fclose(file);
    printf("File saved\n");

}

void loadTasksFromTheFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File could not be opened\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (length >= MAX_TASKS) break; // Jeśli masz limit zadań

        char *sep = strchr(line, ';');
        if (!sep) continue;

        *sep = '\0';
        int completed = atoi(line);
        char *taskText = sep + 1;

        taskText[strcspn(taskText, "\n")] = '\0'; // usuń \n z końca

        tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task));
        tasks[length].task = (char *)malloc(strlen(taskText) + 1);
        strcpy(tasks[length].task, taskText);
        tasks[length].completed = completed;
        length++;
    }

    fclose(file);
    printf("Tasks loaded from file.\n");

}

int main() {
    int choice;
    int indexInput;
    int running = 1;
    char taskInput[200];

    loadTasksFromTheFile("tasks.txt");

    printf("\nOptions\n");
    printf("1. Add task\n");
    printf("2. List tasks\n");
    printf("3. Mark as complete\n");
    printf("4. Edit task\n");
    printf("4. Delete task\n");
    printf("6. Exit (save and quit)\n");

    while (running) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task\n");
                getchar();
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';
                addTask(taskInput);
                break;
            case 2:
                listTasks();
                break;
            case 3:
                printf("Enter index\n");
                scanf("%d", &indexInput);
                markCompleted(indexInput);
                break;
            case 4:
                printf("Enter index\n");
                scanf("%d", &indexInput);
                printf("Enter edited task");
                getchar();
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';

                editTask(indexInput, taskInput);
                break;

            case 5:
                printf("Enter index\n");
                scanf("%d", &indexInput);
                deleteTask(indexInput);
                break;
            case 6:
                saveTasksToTheFile("tasks.txt");
                running = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    free(tasks);
    return 0;
}