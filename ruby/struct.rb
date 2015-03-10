#!/usr/bin/env ruby

# Define the struct
Item = Struct.new( :name, :id, :price )

# Assign from constructor
i = Item.new( "Watermelons", 1337, "$5.40" )
puts i.name
puts i.id
puts i.price

# Or assign after constructor
i.name = "Blue cheese"

# This code is equivalent, but more verbose
class AnotherItem
    attr_accessor :name, :id, :price

    def initialize( *args )
        @name, @id, @price = *args
    end
end

p = AnotherItem.new( "Sardines", 31337, "$0.99" )
puts p.name
puts p.id
puts p.price

