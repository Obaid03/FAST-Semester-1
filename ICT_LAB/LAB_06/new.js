var tasks = [];
// Function to add a task
function addTask(task) {
tasks.push(task);
console.log("Task added: " + task);
}
// Function to remove a task by its index
function removeTask(index) {
if (index >= 0 && index < tasks.length) {
var removedTask = tasks.splice(index, 1);
console.log("Task removed: " + removedTask);
} else {
console.log("Error: Invalid task index.");
}
}
// Function to display all tasks
function displayTasks() {
console.log("To-Do List:");
for (var i = 0; i < tasks.length; i++) {
console.log((i + 1) + ": " + tasks[i]);
}
}
// Function to clear all tasks
function clearTasks() {
tasks = [];
console.log("All tasks cleared.");
}
// Adding tasks
addTask("Completing Assignment");
addTask("Study for Quiz");
addTask("Lab Submission");
// Displaying current tasks
displayTasks();
// Removing the second task (index 1)
removeTask(1);
// Displaying tasks after removal
displayTasks();
// Clearing all tasks
clearTasks();
// Displaying tasks after clearing
displayTasks();
