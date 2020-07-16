---
title: Schedule
layout: single
toc: true
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true
---


{% assign lectures = site.lectures | sort: "number" %}
{% assign assignments = site.assignments | sort: "number" %}
{% assign all_items = lectures | concat: assignments | group_by: 'week'  %}

{% for weeks in all_items %}

<h2 id="week_{{ weeks.name }}">Week - {{ weeks.name }}<a class="header-link" href="#week_{{ weeks.name }}" title="Permalink"><!-- <i class="fa fa-link"></i> --></a></h2>

  <h3 class="no_toc">Lectures</h3>
  <ul>
    {% assign content_items = weeks.items %}
    {% for item in content_items %}
      {% if item.category == "lectures" %}
        <li>
          <a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a>
        </li>
      {% endif %}
    {% endfor %}
  </ul>
  <h3 class="no_toc">Assignments</h3>
  <ul>
    {% assign content_items = weeks.items %}
    {% for item in content_items %}
      {% if item.category == "assignments" %}
        <li>
          <a href="{{ site.baseurl }}{{ item.url }}">#{{ item.number}} - {{ item.title }}</a> 
        (Due: <b>{{ item.date_due }}</b>)
        </li>    
      {% endif %}
    {% endfor %}
  </ul>
{% endfor %}
