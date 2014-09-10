#!/usr/bin/env ruby
require 'ostruct'

i = OpenStruct.new
i.name = "Watermelons"
i.id = 1337
i.price = "$5.40"

puts i.name
puts i.id
puts i.price
