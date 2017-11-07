er() { echo; echo "\$ $@" ; "$@" ; }

echo "Compress"
er ./lzw -c $1
er mv $1 $1.old
echo "Decompress"
er ./lzw -d $1.lzw
echo "Making diff"
er diff $1 $1.old
er mv $1.old $1
