import pandas
import csv

def file_path(extension):
    name_file = input("Put the file's name to read:")

    name_file_split = name_file.split(".")

    if extension != name_file_split[1]:
        return
    
    return name_file


def write_file():

    name_file = file_path("txt")
    f = open(name_file, "w")

    data_list = []
    flag = True

    while flag:
        validation = input("\nDo you wanna add information to the file? (yes or no):")

        if validation == "yes":
            str = input("\nWrite the information (write \"done\" when you finished):")
            while str != "done":
                data_list.append(str)
                str = input("Write the information (write \"done\" when you finished):")
        elif validation == "no":
            flag = False
        else:
            print("Please, put a valid answer\n")


    for data in data_list:
        f.write(f"{data}\n")

    f.close()


def read_file():
    name_file = file_path("txt")

    try:
        f = open(name_file, "r")
    except:
        print("\nError: The file could not be read")
        return

    file_lines = f.readlines()
    for i, file_line in enumerate(file_lines):
        file_line = file_line.replace("\n", "")
        print(f"{i + 1}| {file_line}")
        
        
    f.close()


