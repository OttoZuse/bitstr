from bitclass import Bitstring

bitstr = Bitstring()
# bitstr.set_file_in("file_in")
if bitstr.read_type == 'c':
    bitstr.console_read()
elif bitstr.read_type == 'f':
    bitstr.file_read()
else:
    print("ну и что?")
    bitstr.stop()
bitstr.nulling()
bitstr.con()
bitstr.write()
