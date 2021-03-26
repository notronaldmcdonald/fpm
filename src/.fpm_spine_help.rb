# Foundation Package Manager
# spine_help
# Developed by Brett. (https://github.com/notronaldmcdonald)

# begin script

puts "Welcome to the Help documentation."
puts "Enter the name of the package you would like to access the documentation for."
puts "Please note: Not every package will have help pages."
puts "Enter the name of the package you want to find help documentation for."
helpfile_needed = gets
helpfile_needed = helpfile_needed.chomp
puts "Looking up #{helpfile_needed} on remote..."
system("curl -s https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs/help/#{helpfile_needed}")
puts "\nIf nothing printed, or an error message printed, the package does not have any help documentation."
puts "Passing the ball back..."
