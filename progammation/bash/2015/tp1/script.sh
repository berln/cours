function mystere ()  {
local mot=$1
[ "${mot#${mot%?}}" = "${mot%${mot#?}}" ] 
|| { echo "Pas bon"; return 1; }

mot=${mot%?}
mot=${mot#?}

[ "$mot" ] || { echo "Bon"; return 0; }
mystere "$mot"
}

