#!/usr/bin/env ruby
require 'rubygems'
require 'sinatra'
require 'haml'
require 'dm-core'
require 'dm-migrations'
DataMapper.setup( :default, "sqlite3://#{Dir.pwd}/rolodex.db" )

# Define the model
class Contact
    include DataMapper::Resource

    property :id, Serial
    property :firstname, String
    property :lastname, String
    property :email, String
end

DataMapper.auto_upgrade!

# Show list of contacts
get '/contacts/' do
    haml :list, :locals => { :cs => Contact.all }
end

# Show form to create new contact
get '/contacts/new' do
    haml :form, :locals => {
        :c => Contact.new,
        :action => '/contacts/create'
    }
end

# Create new contact
post '/contacts/create' do
    c = Contact.new
    c.attributes = params
    c.save

    redirect("/contacts/#{c.id}")
end

# Show form to edit contact
get '/contacts/:id/edit' do|id|
    c = Contact.get(id)
    haml :form, :locals => {
        :c => c,
        :action => "/contacts/#{c.id}/update"
    }
end

# Edit a contact
post '/contacts/:id/update' do|id|
    c = Contact.get(id)
    c.update_attributes params

    redirect "/contacts/#{id}"
end

# Delete a contact
post '/contacts/:id/destroy' do|id|
    c = Contact.get(id)
    c.destroy

    redirect "/contacts/"
end

# View a contact
# TODO: Put at bottom?
get '/contacts/:id' do|id|
    c = Contact.get(id)
    haml :show, :locals => { :c => c }
end

__END__
@@ layout
%html
  %head
    %title Rolodex
  %body
    = yield
    %a(href="/contacts/") Contact List

@@form
%h1 Create a new contact
%form(action="#{action}" method="POST")
  %label(for="firstname") First Name
  %input(type="text" name="firstname" value="#{c.firstname}")
  %br

  %label(for="lastname") Last Name
  %input(type="text" name="lastname" value="#{c.lastname}")
  %br

  %label(for="email") Email
  %input(type="text" name="email" value="#{c.email}")
  %br

  %input(type="submit")
  %input(type="reset")
  %br

- unless c.id == 0
  %form(action="/contacts/#{c.id}/destroy" method="POST")
    %input(type="submit" value="Destroy")

@@show
%table
  %tr
    %td First Name
    %td= c.firstname
  %tr
    %td Last Name
    %td= c.lastname
  %tr
    %td Email
    %td= c.email
%a(href="/contacts/#{c.id}/edit") Edit Contact

@@list
%h1 Contacts
%a(href="/contacts/new") New Contact
%table
  - cs.each do|c|
    %tr
      %td= c.firstname
      %td= c.lastname
      %td= c.email
      %td
        %a(href="/contacts/#{c.id}") Show
      %td
        %a(href="/contacts/#{c.id}/edit") Edit

