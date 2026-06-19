#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <ctime>  // For time tracking

using namespace std;

const int TOTAL_PROCESSES = 4;
const int TOTAL_RESOURCES = 6;

// Simulated resource names
string resource_names[TOTAL_RESOURCES] = {
    "Printer", "Scanner", "Disk", "Network", "GPU", "CPU"
};

// Semaphore for each resource
sem_t resource_semaphores[TOTAL_RESOURCES];


pthread_mutex_t console_lock;

// Simulated Ready Queue
queue<int> ready_queue;
pthread_mutex_t queue_lock;

// Thread function for each process
void* run_process(void* arg) {
    int process_id = (intptr_t)arg;

    // Random resource count (1 to TOTAL_RESOURCES)
    int resource_needed = rand() % TOTAL_RESOURCES + 1;
    vector<int> selected_resources;

    // Add process to ready queue
    pthread_mutex_lock(&queue_lock);
    ready_queue.push(process_id);
    pthread_mutex_unlock(&queue_lock);

    // Display ready queue status
    pthread_mutex_lock(&console_lock);
    cout << "\n[READY QUEUE] Current queue: ";
    queue<int> temp_queue = ready_queue;
    while (!temp_queue.empty()) {
        cout << "P" << temp_queue.front() << " ";
        temp_queue.pop();
    }
    cout << endl;
    pthread_mutex_unlock(&console_lock);

    // Choose random unique resources
    while (selected_resources.size() < resource_needed) {
        int res_index = rand() % TOTAL_RESOURCES;
        if (find(selected_resources.begin(), selected_resources.end(), res_index) == selected_resources.end()) {
            selected_resources.push_back(res_index);
        }
    }

    pthread_mutex_lock(&console_lock);
    cout << "[Process P" << process_id << "] requesting " << resource_needed << " resource(s): ";
    for (int res_id : selected_resources) {
        cout << resource_names[res_id] << " ";
    }
    cout << endl;
    pthread_mutex_unlock(&console_lock);

    // Acquire all required semaphores
    for (int res_id : selected_resources) {
        sem_wait(&resource_semaphores[res_id]);
    }

    // Remove from ready queue
    pthread_mutex_lock(&queue_lock);
    if (!ready_queue.empty() && ready_queue.front() == process_id) {
        ready_queue.pop();
    }
    pthread_mutex_unlock(&queue_lock);

    // Show acquired resources
    pthread_mutex_lock(&console_lock);
    cout << "[Process P" << process_id << "] acquired: ";
    for (int res_id : selected_resources) {
        cout << resource_names[res_id] << " ";
    }
    cout << endl;
    pthread_mutex_unlock(&console_lock);

    // **Random sleep to simulate usage **
    int work_time = rand() % 3 + 2; // Generates a random value 

    pthread_mutex_lock(&console_lock);
    cout << "[Process P" << process_id << "] using resources for " << work_time << " second(s)." << endl;
    pthread_mutex_unlock(&console_lock);

    sleep(work_time);  // Sleep for the random work time

    // Release all resources
    for (int res_id : selected_resources) {
        sem_post(&resource_semaphores[res_id]);
    }

    pthread_mutex_lock(&console_lock);
    cout << "[Process P" << process_id << "] finished and released all resources.\n" << endl;
    pthread_mutex_unlock(&console_lock);

    return nullptr;
}

int main() {
    pthread_t process_threads[TOTAL_PROCESSES];
    srand(static_cast<unsigned int>(time(nullptr))); // Seed RNG

    // Initialize semaphores (1 per resource)
    for (int i = 0; i < TOTAL_RESOURCES; ++i) {
        sem_init(&resource_semaphores[i], 0, 1);
    }

    pthread_mutex_init(&console_lock, nullptr);
    pthread_mutex_init(&queue_lock, nullptr);

    // Generate random process execution order
    vector<int> execution_order(TOTAL_PROCESSES);
    for (int i = 0; i < TOTAL_PROCESSES; ++i) execution_order[i] = i;
    random_shuffle(execution_order.begin(), execution_order.end());

    // Create threads using randomized process IDs
    for (int i = 0; i < TOTAL_PROCESSES; ++i) {
        pthread_create(&process_threads[i], nullptr, run_process, (void*)(intptr_t)execution_order[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < TOTAL_PROCESSES; ++i) {
        pthread_join(process_threads[i], nullptr);
    }

    // Cleanup
    for (int i = 0; i < TOTAL_RESOURCES; ++i) {
        sem_destroy(&resource_semaphores[i]);
    }
    pthread_mutex_destroy(&console_lock);
    pthread_mutex_destroy(&queue_lock);

    cout << "\n[System] All processes have completed successfully.\n" << endl;
    return 0;
}
