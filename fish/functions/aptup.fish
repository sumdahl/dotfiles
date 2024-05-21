function aptup --wraps='sudo apt update && sudo apt full-upgrade' --description 'alias aptup=sudo apt update && sudo apt full-upgrade'
  sudo apt update && sudo apt full-upgrade $argv; 
end
