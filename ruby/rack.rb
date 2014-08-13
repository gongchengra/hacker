# my_rack_app.rb

require 'rack'

app = Proc.new do |env|
    ['200', {'Content-Type' => 'text/html'}, ['A barebones rack app.']]
end

Rack::Handler::WEBrick.run app, :Port => 9292

# require 'rubygems'
# require 'rack'

# class HelloWorld
#     def call(env)
#         [200, {"Content-Type" => "text/html"}, "Hello Rack!"]
#     end
# end

# Rack::Handler::Mongrel.run HelloWorld.new, :Port => 9292
