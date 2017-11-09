er() { echo; echo "\$ $@" ; echo; $@ ; }

echo "Compress"
echo "./lzw -c $1"
time ./lzw -c $1
echo
er mv $1 $1.old
echo "Decompress"
echo "./lzw -d $1.lzw"
time ./lzw -d $1.lzw
echo
echo "Making diff"
er diff $1 $1.old

echo "Moving decompressed version"
er mv $1 $1.dec
echo "Restoring original file"
er cp $1.old $1
#echo "Removing compressed"
#er rm $1.lzw
