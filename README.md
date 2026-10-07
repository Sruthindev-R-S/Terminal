# Human-Friendly CLI Command Layer

This project provides a small command layer that converts simple, human-readable commands into filesystem operations. Instead of remembering shell commands such as `mkdir`, `touch`, or `rm -r`, users can enter named commands that are mapped to C++ command objects.

## How It Works

1. `main.cpp` reads the command name and its argument.
2. `util/map.h` maps the command name to a command factory.
3. The factory creates a class derived from `BaseCommand`.
4. The command receives its argument and executes the corresponding operation.

The mapping layer keeps command selection separate from command implementation. New commands can be added by creating a `BaseCommand` implementation and registering its factory in `util/map.h`.

## Supported Commands

| Human command | Operation | Example |
| --- | --- | --- |
| `CREATE_FOLDER` | Creates a directory | `CREATE_FOLDER documents` |
| `CREATE_FILE` | Creates an empty file | `CREATE_FILE notes.txt` |
| `WRITE_FILE` | Writes text to a file | `WRITE_FILE notes.txt Hello from the CLI` |
| `DELETE_FILE` | Deletes a file | `DELETE_FILE notes.txt` |
| `DELETE_FOLDER` | Deletes a folder recursively | `DELETE_FOLDER documents` |

## Writing Large Text

`WRITE_FILE` accepts text after the filename. Additional lines can be entered until end-of-file is sent:

```text
WRITE_FILE story.txt This is the first line
This is the second line.
This is the third line.
```

On Linux, press `Ctrl+D` on an empty line to finish entering text. The text is then written to the requested file.

## Build

Requirements:

- C++17 compiler
- CMake 3.16 or newer

Configure and build:

```bash
cmake -S . -B build
cmake --build build
```

Run the program:

```bash
./build/command_runner
```

## Project Structure

```text
.
├── main.cpp
├── CMakeLists.txt
├── commands/
│   ├── base.h
│   ├── CreateFolder.h
│   ├── CreateFile.h
│   ├── WiteFile.h
│   ├── DeleteFile.h
│   └── DeleteFolder.h
└── util/
    └── map.h
```

## Adding a Command

1. Create a class derived from `BaseCommand`.
2. Implement `input()` and `execute()`.
3. Include the new header in `util/map.h`.
4. Add a `CommandFactory` entry for the human-facing command name.

All filesystem commands should be tested carefully because they operate on paths supplied by the user.
