# Usage: 
# sh ./code-style-check.sh ${c_source_file_name}

indent -npro -nbad -nip -lp -npsl -npcs -i4 -ts4 -sob -br -ce -nut -bap -nbc -bbo -brs -cs -nfc1 -nfca -hnl -ip0 -nprs -saf -sai -saw -ci4 -cli0 -l200 $*

echo "$*" "is the new generated source file"
echo "$*~" "is the original source file"

