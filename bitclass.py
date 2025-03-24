from sys import exit
class Bitstring:
    def __init__(self):
        self.file_read_name = ''
        self.read_type = input("Читать из файла?[f]/Читать из консоли?[c] ")
    def stop(self):
        exit()
    def set_file_in(self, file_read_name):
        self.file_read_name = file_read_name
    def str_to_listint(self, string):
        listint = []
        for i in string:
            if i != '0' and i != '1' and i != '\n':
                print("Строка должна быть двоичной")
                self.stop()
        for i in string:
            if i != '\n':
                listint.append(int(i))
        return listint
    def console_read(self):
        self.str1 = self.str_to_listint(input())
        self.str2 = self.str_to_listint(input())
        self.len1 = len(self.str1)
        self.len2 = len(self.str2)
    def file_read(self):
        if not self.file_read_name:
            self.file_read_name = input("Введите имя файла: ")
        try:
            file = open(self.file_read_name)
        except IOError:
            print("Файла - ", self.file_read_name, " не существует")
            self.stop()
        self.str1 = self.str_to_listint(file.readline())
        self.str2 = self.str_to_listint(file.readline())
        self.len1 = len(self.str1)
        self.len2 = len(self.str2)
        file.close()
    def nulling(self):
        if self.len1 > self.len2:
            self.len = self.len1
            for i in range(self.len2, self.len1):
                self.str2.append(0)
        else:
            self.len = self.len2
            for i in range(self.len1, self.len2):
                self.str1.append(0)
    def con(self):
        self.listcon = []
        for i in range(0, self.len):
            self.listcon.append(self.str1[i] * self.str2[i])
            self.strcon = ''.join(str(i) for i in self.listcon)
            self.strcon += '\n'
    def get_strcon(self):
        return self.strcon
    def write(self):
        type_of_write = input("Записывать в файл?[f]/Выводить в консоль?[с] ")
        if type_of_write == 'c':
            print(self.get_strcon())
        elif type_of_write == 'f':
            file_write = input("Введите имя файла: ")
            try:
                file = open(file_write, 'w')
            except IOError:
                print("Ошибка записи в файл")
                exit()
            file.write(self.strcon)
            file.close()
