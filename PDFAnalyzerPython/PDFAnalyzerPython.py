#! python3

def count_lines(text):
    return len(text.splitlines())

def count_words(text):
    return len(text.split())

def count_characters(text):
    return len(text)

while True:
    filename = input("Enter a filename: ")

    try:
        with open(filename, 'r') as file:
            contents = file.read()

        break

    except FileNotFoundError:
        print('Sorry, file not found.')


char_count = count_characters(contents)
line_count = count_lines(contents)
word_count = count_words(contents)


report = ('\n' + '*' * 26 + '\n' + 'File Analyzer v1.0'.center(26) + '\n' + '*' * 26 + '\n' + 'File: '.ljust(13) + f'{filename}'.rjust(13) + '\n'
          + 'Lines: '.ljust(13) + f' {line_count}'.rjust(13) + '\n' + 'Words: '.ljust(13) + f' {word_count}'.rjust(13) + '\n'
          + 'Characters: '.ljust(13) + f'{char_count}'.rjust(13) + '\n')
print(report)

report_name = input('Enter report filename: ')

with open(report_name,'w') as outFile:
    outFile.write(report)

