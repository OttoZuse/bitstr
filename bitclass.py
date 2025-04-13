from sys import exit
class Bitstring:
    def __init__(self):
        self.file_read_name = ''
        self.file_write_name = ''
        self.bitstr = []
        self.listcon = ''
        self.len = 0
    def stop(self):
        exit()
    def set_file_in(self, file_read_name):
        self.file_read_name = file_read_name
    def set_file_out(self, file_write_name):
        self.file_write_name = file_write_name
    def set_bitstr(self, bitstr):
        self.bitstr = self.str_to_listint(bitstr)
        self.len = len(self.bitstr)
    def str_to_listint(self, string):
        listint = []
        for i in string:
            if i != '0' and i != '1' and i != '\n':
                print("Строка должна быть двоичной")
                self.stop()
            elif i != '\n':
                listint.append(int(i))
        return listint
    def read(self):
        if not self.bitstr:
            read_type = input("Читать из файла?[f]Читать из консоли?[c] ")
            if read_type == 'c':
                self.console_read()
            elif read_type == 'f':
                self.file_read()
            else:
                self.stop()
    def console_read(self):
        self.bitstr = self.str_to_listint(input())
        self.len = len(self.bitstr)
    def file_read(self):
        if not self.file_read_name:
            self.file_read_name = input("Введите имя файла: ")
        try:
            file = open(self.file_read_name)
        except IOError:
            print("Файла - ", self.file_read_name, " не существует")
            self.stop()
        self.bitstr = self.str_to_listint(file.readline())
        self.len = len(self.bitstr)
        file.close()
    def nulling(self, len2):
        if self.len < len2:
            for i in range(self.len, len2):
                self.bitstr.append(0)
            self.len = len2
            self.listcon = ''.join(str(i) for i in self.bitstr)
    def con(self, bitobj):
        bitstr2 = bitobj.bitstr
        for i in range(0, self.len):
            self.bitstr[i] *= bitstr2[i]
        print(self.bitstr)
        self.listcon = ''.join(str(i) for i in self.bitstr)
        # return this
    def get_strcon(self):
        return self.bitstr
    def get_len(self):
        return self.len
    def write(self):
        type_of_write = input("Записывать в файл?[f]/Выводить в консоль?[с] ")
        if type_of_write == 'c':
            print(self.listcon)
        elif type_of_write == 'f':
            file_write = input("Введите имя файла: ")
            try:
                file = open(file_write, 'w')
            except IOError:
                print("Ошибка записи в файл")
                exit()
            file.write(self.listcon)
            file.close()
