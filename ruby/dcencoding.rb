#!/usr/bin/env ruby
require 'scanf'
sum = 0
array = scanf('%s')
# array << "\n"
array.join('').each_byte {|c| sum = sum*256 +c}
puts sum

