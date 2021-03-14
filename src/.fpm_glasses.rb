# Foundation Package Manager
# fpm_glasses - interactive search utility
# Linux Only
# Developed by Brett. (https://github.com/notronaldmcdonald)

# dependency

require 'colorize'

# variables

home = Dir.home
# USER - add your repositories here and add an additional search line.
core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/index.txt"
test = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/live/pkgs/index.txt"

# begin script

puts "Welcome!".green
puts "\nFPM Glasses 0.1.0"
puts "Enter a search target: ".yellow
query = gets
query = query.chomp
puts "Okay! Looking up #{query}...".blue
# this is the search line
system("curl -s #{core} -o .index.tmp")
# the search line is above
system("grep -w #{query} .index.tmp > .output.tmp")
s = File.size(".output.tmp")
sleep(1)
if s == 0
  puts "Package #{query} doesn't seem to exist. Sorry!".red
else
  puts "Package #{query} seems to exist.".green
end
puts "glasses: cleaning up"
sleep(2)
system("rm -f .index.tmp")
system("rm -f .output.tmp")
