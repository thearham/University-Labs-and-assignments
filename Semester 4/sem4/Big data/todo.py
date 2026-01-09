import json


def load_tasks():
    try:
        with open("tasks.json", "r") as file:
            tasks = json.load(file)
    except FileNotFoundError:
        tasks = []
    return tasks


def save_tasks(tasks):
    with open("tasks.json", "w") as file:
        json.dump(tasks, file, indent=2)


def display_tasks(tasks):
    print("To-Do List:")
    if not tasks:
        print("No tasks.")
    else:
        for index, task in enumerate(tasks, start=1):
            status = " [Done]" if task["done"] else " [Not Done]"
            print(f"{index}. {task['description']}{status}")


def add_task(tasks, description):
    tasks.append({"description": description, "done": False})
    save_tasks(tasks)
    print(f"Task '{description}' added.")


def mark_done(tasks, index):
    if 1 <= index <= len(tasks):
        tasks[index - 1]["done"] = True
        save_tasks(tasks)
        print(f"Task {index} marked as done.")
    else:
        print("Invalid task index.")


def main():
    tasks = load_tasks()

    while True:
        print("\nMenu:")
        print("1. Display To-Do List")
        print("2. Add Task")
        print("3. Mark Task as Done")
        print("4. Quit")

        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            display_tasks(tasks)
        elif choice == "2":
            description = input("Enter task description: ")
            add_task(tasks, description)
        elif choice == "3":
            index = int(input("Enter the task index to mark as done: "))
            mark_done(tasks, index)
        elif choice == "4":
            print("Quitting the To-Do List application. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")

if __name__ == "__main__":
    main()
