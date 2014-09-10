#!/usr/bin/env ruby

grades = Hash.new

grades["Bob"] = 82
grades["Jim"] = 94
grades["Billy"] = 58

grades = {
    "Bob" => 82,
    "Jim" => 94,
    "Billy" => 58
}

puts grades["Jim"]
grades.each do |name,grade|
    puts "#{name}: #{grade}"
end
hash = { :some_key => 'some value', :another_key => 22 }
hash = { some_key:'some value', another_key:22 }
puts hash['some_key']
