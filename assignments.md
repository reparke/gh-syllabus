---
title: Assignments
layout: category
category: assignments
classes: wide
---


<ul>
{% assign all_assignments = site.assignments | sort: "number" %}
{% for week in all_assignments %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">#{{ week.number}} - {{ week.title }}</a> 
  	(Due: <b>{{ week.date_due }}</b>)</li>
{% endfor %}
</ul>





