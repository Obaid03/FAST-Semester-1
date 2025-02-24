const prompt = require('prompt-sync')();

let tasks = [];

function addTask() {
    const task = prompt('Enter the task: ');
    tasks.push(task);
    console.log(`Task "{task}" added successfully.`);
}

function removeTask() {
    displayTasks();
    const index = parseInt(prompt('Enter the task index to remove: '));
    if (isNaN(index) || index < 0 || index >= tasks.length) {
        console.log('Invalid index. Please try again.');
    } else {
        const removedTask = tasks.splice(index, 1);
        console.log(`Task "{removedTask}" removed successfully.`);
    }
}

function displayTasks() {
    if (tasks.length === 0) {
        console.log('No tasks in the list.');
    } else {
        console.log('Current tasks:');
        tasks.forEach((task, index) => {
            console.log(`{index}: {task}`);
        });
    }
}

function clearTasks() {
    tasks = [];
    console.log('All tasks cleared.');
}

function main() {
    console.log('To-Do List Manager');
    console.log('Commands: add, remove, view, clear, exit');
    let running = true;

    while (running) {
        const command = prompt('Enter a command: ').toLowerCase();

        switch (command) {
            case 'add':
                addTask();
                break;
            case 'remove':
                removeTask();
                break;
            case 'view':
                displayTasks();
                break;
            case 'clear':
                clearTasks();
                break;
            case 'exit':
                running = false;
                console.log('Exiting program. Goodbye!');
                break;
            default:
                console.log('Invalid command. Please try again.');
        }
    }
}

main();
