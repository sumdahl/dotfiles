function pacob --wraps='sudo pacman -R $(pacman -Qdtq)' --description 'alias pacob=sudo pacman -R $(pacman -Qdtq)'
  sudo pacman -R $(pacman -Qdtq) $argv
        
end
