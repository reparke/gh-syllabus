---
title: Weekly Schedule
layout: single
toc: false
toc_label: "Quick Links"
toc_icon: "bookmark"  # corresponding Font Awesome icon name (without fa prefix)
toc_sticky: true
---
{{site.baseurl}}
9
{{site.calendar.semester_num_weeks}}


{% capture dates_string %}
  {% include /functions/calc_week_dates.html %}
{% endcapture %}
{% assign dates_array = dates_string | split: '::'%}	
bar

{% assign lectures = site.lectures | sort: "number" %}
{% assign assignments = site.assignments | sort: "number" %}
{% assign all_items = lectures | concat: assignments | group_by: 'week'  %}

{% for weeks in all_items %}
{% comment %}
  Capture stores strings so convert to int to use in array
{% endcomment %}
{% assign index = weeks.name | times: 1 %} 

{% assign current_dates = dates_array[index] | split: '|' %}

<h2 id="week_{{ weeks.name }}">Week - {{ weeks.name }} {{ current_dates[0] }}
<a class="header-link" href="#week_{{ weeks.name }}" title="Permalink"><!-- <i class="fa fa-link"></i> --></a></h2>
<div class="weekly_schedule_content_area">
    <h3 class="no_toc weekly_schedule_content_label">Reading / Video (pre-lecture material)</h3>
    <ul><li class="weekly_schedule_content_item">TBD</li></ul>
    <ul>
      {% assign content_items = weeks.items %}
      {% for item in content_items %}
        {% if item.category == "reading" %}
          <li class="weekly_schedule_content_item">
            <a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a>
          </li>
        {% endif %}
      {% endfor %}
    </ul>
  </div>
  <div class="weekly_schedule_content_area">
    <h3 class="no_toc weekly_schedule_content_label">Lectures</h3>
    <ul>
      {% assign content_items = weeks.items %}
      {% for item in content_items %}
        {% if item.category == "lectures" %}
          <li class="weekly_schedule_content_item">
            <a href="{{ site.baseurl }}{{ item.url }}">{{ item.title }}</a>
          </li>
        {% endif %}
      {% endfor %}
    </ul>
  </div>
  <div class="weekly_schedule_content_area">
    <h3 class="no_toc weekly_schedule_content_label">Assignments</h3>
    <ul>
      {% assign content_items = weeks.items %}
      {% for item in content_items %}
        {% if item.category == "assignments" %}
          <li class="weekly_schedule_content_item">
            <a href="{{ site.baseurl }}{{ item.url }}">#{{ item.number}} - {{ item.title }}</a> 
          (Due: <b>{{ item.date_due }}</b>)
          </li>    
        {% endif %}
      {% endfor %}
    </ul>
  </div>
{% endfor %}
