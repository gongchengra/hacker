#!/usr/bin/env ruby

module ModuleA
    def ModuleA.message
        puts "Hello from ModuleA"
    end
end

module ModuleB
    def ModuleB.message
        puts "Hello from ModuleB"
    end
end

ModuleA::message
ModuleB::message

