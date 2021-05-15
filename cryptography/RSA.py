"""
Marta Dzięgielewska
RSA
07.04.2020
"""

from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

# generujemy klucz publiczny i prywatny, wybrałam klucz 1024 bitowy ze względu na to, że tekst w pliku, który chcę zaszyfrować jest krótki
# w innym wypadku można wziąć klucz 2048 bitowy lub 3072
# klucz publiczny jest reprezentowany przez parę (n, e), gdzie n jest iloczynem dwóch liczb, a e publiczną eksponentą
# a prywatny - (n, d), gdzie d jest prywatną eksponentą
Pair_key = RSA.generate(1024)
public_key = Pair_key.publickey()
private_key = Pair_key.exportKey

# otwieramy plik, który chcemy zaszyfrować i w którym chcemy umieścić zaszyfrowany tekst
file_to_encrypt = open("file1.txt", 'rb')
text = file_to_encrypt.read()
encrypted_file = open("file2.txt", 'wb')

# PKCS1_OAEP to algorytm RSA, który wykorzystuje padding, aby zapewnić większe bezpieczeństwo szyfrowania
encryptor = PKCS1_OAEP.new(public_key)
# tekst jest wypełniany zerami, aby jego długość zgadzała się z kluczem
# a następnie kodowana za pomocą modulo n
encrypted = encryptor.encrypt(text)
# umieszczamy zaszyfrowany tekst w pliku, użycie binascii.hexlify sprawia, że jest on zamieniony na system szesnastkowy i jest bardziej czytelny
encrypted_file.write(binascii.hexlify(encrypted))

file_to_encrypt.close()
encrypted_file.close()

file_to_decrypt = open("file2.txt", 'rb')
text = file_to_decrypt.read()
decrypted_file = open("file3.txt", 'wb')

decryptor = PKCS1_OAEP.new(Pair_key)
decrypted = decryptor.decrypt(encrypted)
decrypted_file.write(decrypted)

file_to_decrypt.close()
decrypted_file.close()
