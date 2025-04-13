from bitclass import Bitstring

bitstr1 = Bitstring()
bitstr2 = Bitstring()
bitstr1.set_bitstr("00111101")
bitstr2.set_bitstr("110101100111")
bitstr1.read()
bitstr2.read()
bitstr1.nulling(bitstr2.get_len())
bitstr1.con(bitstr2)
bitstr1.write()
