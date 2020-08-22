---
title: Lectures
category: lectures
layout: single
classes: wide
toc: true
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true
---


{% capture dates_string %}
  {% include /functions/calc_week_dates.html %}
{% endcapture %}
{% assign dates_array = dates_string | split: '::'%}	



{% assign all_lectures = site.lectures | group_by: 'week' %}
{% for week in all_lectures %}
{% assign index = week.name | times: 1 %} 
{% assign current_dates = dates_array[index] | split: '|' %}
{% if index != 16 %}
<h2 id="week_{{ week.name }}">Week {{ week.name }} ({{current_dates[2] | strip}} - {{current_dates[3] | strip}})<a class="header-link" href="#week_{{ week.name }}" title="Permalink"></a></h2>
<ul>
    {% assign items = week.items | sort: 'order' %}
    {% for item in items %}
      {% if item.show_in_list == false %}
        {% continue %}
      {% endif %}
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>
{% endif %}
{% endfor %}

{% comment %}
It is inefficient to have identical for loops (one for current semester content and one for bonus material. 
Consider revising and possibly using Liquid sort function
{% endcomment %}

{% for week in all_lectures %}
{% assign index = week.name | times: 1 %} 
{% assign current_dates = dates_array[index] | split: '|' %}
{% if index == 16 %}
<h2 id="#bonus_material">Bonus Material<a class="header-link" href="#bonus_material" title="Permalink"></a></h2>
<ul>
    {% assign items = week.items | sort: 'order' %}
    {% for item in items %}
      {% if item.show_in_list == false %}
        {% continue %}
      {% endif %}    
    <li><a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a></li>
    {% endfor %}
</ul>
{% endif %}
{% endfor %}
